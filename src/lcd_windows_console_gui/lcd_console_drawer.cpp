#include <stdafx.h>
#include "lcd_console_drawer.h"

#include <iostream>
#include <windows.h>
#include <HD44780.h>

static const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
static constexpr int char_width = 5;
static constexpr int char_height = 8;

static constexpr int margin_horiz = 2;
static constexpr int margin_vert = 2;
static constexpr int padding_horiz = 1;
static constexpr int padding_vert = 1;

namespace opensalad
{
	namespace lcd
	{
		lcd_console_drawer::lcd_console_drawer(int cols, int rows)
			: m_rowsCount(rows)
			, m_columnsCount(cols)
			, m_screenBuffer(screen_size_in_bytes())
		{
		}

		void lcd_console_drawer::setup()
		{
			m_controller = std::make_shared<HD44780>();

			CONSOLE_FONT_INFOEX font;
			font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
			font.dwFontSize.X = 4;
			font.dwFontSize.Y = 4;
			font.FontFamily = FF_DONTCARE;
			font.FontWeight = FW_NORMAL;

			SetCurrentConsoleFontEx(console_handle, false, &font);
			DWORD console_mode = 0;
			GetConsoleMode(console_handle, &console_mode);
			SetConsoleMode(console_handle, console_mode & (~ENABLE_ECHO_INPUT));
			set_colors();
			for (int i = 0; i < screen_size_in_bytes(); ++i)
			{
				m_screenBuffer[i] = ' ';
			}
		}

		void lcd_console_drawer::set_colors() const
		{
			CONSOLE_SCREEN_BUFFER_INFOEX console_info;
			console_info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
			GetConsoleScreenBufferInfoEx(console_handle, &console_info);

			COORD c;
			c.X = m_columnsCount * char_width + 2 * margin_horiz + (m_columnsCount - 1) * padding_horiz;
			c.Y = m_rowsCount * char_height + 2 * margin_vert + (m_rowsCount - 1) * padding_vert;
			console_info.srWindow.Left = 0;
			console_info.srWindow.Right = c.X;
			console_info.srWindow.Top = 0;
			console_info.srWindow.Bottom = c.Y;
			console_info.dwSize = c;
			console_info.ColorTable[0] = m_bgColor;
			console_info.ColorTable[7] = m_fgColor;
			SetConsoleScreenBufferInfoEx(console_handle, &console_info);
		}

		void lcd_console_drawer::flush()
		{
			WriteConsole(console_handle, m_screenBuffer.data(), screen_size_in_bytes(), nullptr, nullptr);
		}

		char* lcd_console_drawer::pixel_pointer(int x, int y)
		{
			return m_screenBuffer.data() + y * screen_line_pixel_count() + x;
		}

		char* lcd_console_drawer::char_at(int col, int row, int x, int y)
		{
			return pixel_pointer(
				col * char_width + x + margin_horiz + col * padding_horiz,
				row * char_height + y + margin_vert + row * padding_vert
			);
		}

		void lcd_console_drawer::draw_character(int col, int row, uint8_t const* pixels)
		{
			char symbol_full = 219;
			char symbol_empty = ' ';

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (pixels[i] & (1 << j))
						*char_at(col, row, 4 - j, i) = symbol_full;
					else
						*char_at(col, row, 4 - j, i) = symbol_empty;
				}
			}
		}

		void lcd_console_drawer::run()
		{
			while (1)
			{
				draw();
			}
		}

		void lcd_console_drawer::draw()
		{
			double light_intencity = std::dynamic_pointer_cast<iface::i_lcd_controller_simplified>(m_controller)->get_light_intencity();

			int bgred = 0xa8 * max(0, light_intencity);
			int bggreen = 0xc6 * max(0, light_intencity);
			int bgblue = 0x4e * max(0, light_intencity);

			int fgred = 0x3c * max(0, light_intencity);
			int fggreen = 0x41 * max(0, light_intencity);
			int fgblue = 0x2c * max(0, light_intencity);

			m_bgColor = (bgred | bggreen << 8 | bgblue << 16) & 0x00ffffff;
			m_fgColor = (fgred | fggreen << 8 | fgblue << 16) & 0x00ffffff;

			set_colors();

			for (int i = 0; i < m_columnsCount; ++i)
			{
				for (int j = 0; j < m_rowsCount; ++j)
				{
					const uint8_t* pixels = std::dynamic_pointer_cast<iface::i_lcd_controller_simplified>(m_controller)->
						get_character_at(i + (j % 2) * 0x28 + (j / 2) * m_columnsCount);
					draw_character(i, j, pixels);
				}
			}

			flush();
		}

		std::weak_ptr<iface::i_lcd_controller> lcd_console_drawer::get_controller() const
		{
			return m_controller;
		}

		int lcd_console_drawer::screen_line_pixel_count() const
		{
			return m_columnsCount * char_width + 2 * margin_horiz + (m_columnsCount - 1) * padding_horiz;
		}

		int lcd_console_drawer::screen_size_in_bytes() const
		{
			return (m_columnsCount * char_width + (m_columnsCount - 1) * padding_horiz + 2 * margin_horiz) *
				(m_rowsCount * char_height + (m_rowsCount - 1) * padding_vert + 2 * margin_vert);
		}
	}
}