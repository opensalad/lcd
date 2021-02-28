// #include <lcd.h>

// #include "lcd_console_drawer.h"
// #include <iostream>

// int main(int argc, char** argv)
// {
// 	std::shared_ptr<opensalad::lcd::lcd_console_drawer> lcd_drawer = std::make_shared<opensalad::lcd::lcd_console_drawer>();
// 	opensalad::lcd::lcd lcd(lcd_drawer);

// 	while (1)
// 	{
// 		std::string command;
// 		std::cin >> command;

// 		if (command == "exit")
// 			break;
// 		else if (command == "write")
// 		{
// 			std::cin >> command;
// 			for (opensalad::lcd::byte_t byte : command)
// 				lcd.send_data(byte);
// 		}
// 	}

// 	return 0;
// }

#include<windows.h>

static const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
static constexpr int screen_width = 16;
static constexpr int screen_height = 2;
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

void setup()
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

void flush()
{
	WriteConsole(console_handle, screen_buffer, screen_size_in_bytes, nullptr, nullptr);
}

char* pixel_pointer(int x, int y)
{
	return screen_buffer + y * screen_line_pixel_count + x;
}

char* char_at(int col, int row, int x, int y)
{
	return pixel_pointer(
		col * char_width + x + margin_horiz + col * padding_horiz,
		row * char_height + y + margin_vert + row * padding_vert
	);
}

void draw_character(int row, int col, std::array<uint8_t, 8> pixels)
{
	char symbol_full = 219;
	char symbol_empty = ' ';

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (pixels[i] & (1 << j))
				*char_at(row, col, 4 - j, i) = symbol_full;
			else
				*char_at(row, col, 4 - j, i) = symbol_empty;
		}
	}
}

#include <iostream>

int main()
{
	setup();

	for (int i = 0; i < 2; ++i)
	{
		draw_character(0, i, {
			0b00010001,
			0b00010001,
			0b00010001,
			0b00011111,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00000000,
		});
		draw_character(1, i, {
			0b00011111,
			0b00010000,
			0b00010000,
			0b00011110,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(2, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(3, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(4, i, {
			0b00001110,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00001110,
			0b00000000,
		});
		draw_character(5, i, {
			0b00010001,
			0b00010001,
			0b00010001,
			0b00011111,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00000000,
		});
		draw_character(6, i, {
			0b00011111,
			0b00010000,
			0b00010000,
			0b00011110,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(7, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(8, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(9, i, {
			0b00001110,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00001110,
			0b00000000,
		});
		draw_character(10, i, {
			0b00010001,
			0b00010001,
			0b00010001,
			0b00011111,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00000000,
		});
		draw_character(11, i, {
			0b00011111,
			0b00010000,
			0b00010000,
			0b00011110,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(12, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(13, i, {
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111,
			0b00000000,
		});
		draw_character(14, i, {
			0b00001110,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00001110,
			0b00000000,
		});
		draw_character(15, i, {
			0b00010001,
			0b00010001,
			0b00010001,
			0b00011111,
			0b00010001,
			0b00010001,
			0b00010001,
			0b00000000,
		});
	}

	flush();
	std::cin.ignore();

	return 0;
}