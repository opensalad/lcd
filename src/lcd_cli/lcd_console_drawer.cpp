#include "lcd_console_drawer.h"

#include <iostream>
#include <windows.h>
#include <HD44780.h>

static const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
static constexpr int screen_width = 16;
static constexpr int screen_height = 4;
static constexpr int char_width = 5;
static constexpr int char_height = 8;

static constexpr int margin_horiz = 2;
static constexpr int margin_vert = 2;
static constexpr int padding_horiz = 1;
static constexpr int padding_vert = 1;

static constexpr int screen_line_pixel_count = screen_width * char_width + 2 * margin_horiz + (screen_width - 1) * padding_horiz;

static constexpr long screen_size_in_bytes =
	(screen_width * char_width + (screen_width - 1) * padding_horiz + 2 * margin_horiz) *
	(screen_height * char_height + (screen_height - 1) * padding_vert + 2 * margin_vert);
static char screen_buffer[screen_size_in_bytes] {};

namespace opensalad
{
	namespace lcd
	{
		lcd_console_drawer::lcd_console_drawer()
		{
			setup();
		}

		void lcd_console_drawer::setup()
		{
			CONSOLE_FONT_INFOEX font;
			font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
			font.dwFontSize.X = 4;
			font.dwFontSize.Y = 4;
			font.FontFamily = FF_DONTCARE;
			font.FontWeight = FW_NORMAL;

			CONSOLE_SCREEN_BUFFER_INFOEX console_info;
			console_info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
			GetConsoleScreenBufferInfoEx(console_handle, &console_info);

			COORD c;
			c.X = screen_width * char_width + 2 * margin_horiz + (screen_width - 1) * padding_horiz;
			c.Y = screen_height * char_height + 2 * margin_vert + (screen_height - 1) * padding_vert;
			console_info.dwSize = c;

			console_info.srWindow.Left = 0;
			console_info.srWindow.Right = c.X;
			console_info.srWindow.Top = 0;
			console_info.srWindow.Bottom = c.Y;
			console_info.ColorTable[0] = 0x004ec6a8;
			console_info.ColorTable[7] = 0x002c413c;

			SetCurrentConsoleFontEx(console_handle, false, &font);
			SetConsoleScreenBufferInfoEx(console_handle, &console_info);

			for (int i = 0; i < screen_size_in_bytes; ++i)
			{
				screen_buffer[i] = ' ';
			}
		}


		void lcd_console_drawer::flush()
		{
			WriteConsole(console_handle, screen_buffer, screen_size_in_bytes, nullptr, nullptr);
		}

		char* lcd_console_drawer::pixel_pointer(int x, int y)
		{
			return screen_buffer + y * screen_line_pixel_count + x;
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

		void lcd_console_drawer::draw(char* buffer, int width, int height)
		{
			for (int i = 0; i < width; ++i)
			{
				for (int j = 0; j < height; ++j)
				{
					const uint8_t* pixels = HD44780::get_char(buffer[i + width * j]);
					draw_character(i, j, pixels);
				}
			}

			flush();
		}
	}
}