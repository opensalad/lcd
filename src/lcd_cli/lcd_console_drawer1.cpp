/*#include "lcd_console_drawer.h"

#include <iostream>

namespace opensalad
{
	namespace lcd
	{
		void lcd_console_drawer::draw()
		{
			draw_internal();
		}

		void lcd_console_drawer::set_char_at(position_t const& pos, byte_t character)
		{
			size_t converted_pos = convert_coordinate(pos);
			if (converted_pos > m_dimensions.width * m_dimensions.height)
				return;

			m_char_buffer[converted_pos] = character;
		}

		void lcd_console_drawer::set_char_buffer(position_t const& pos, std::vector<byte_t> const& buffer)
		{
			m_char_buffer = buffer;
		}

		void lcd_console_drawer::set_pin_count(byte_t count)
		{
			m_pin_count = count;
		}

		void lcd_console_drawer::set_pinout(std::vector<std::string> const& pinout)
		{
			m_pinout_naming = pinout;
		}

		void lcd_console_drawer::set_dimension(dimensions_t screen_dimension)
		{
			m_dimensions = screen_dimension;
			m_char_buffer.resize(screen_dimension.width * screen_dimension.height, 0);
		}

		void lcd_console_drawer::set_backlight_intencity(byte_t backlight_intencity)
		{
			m_backlight_intencity = backlight_intencity;
		}

		void lcd_console_drawer::set_backlight_color(color_t backlight_color)
		{
			m_backlight_color = backlight_color;
		}

		void lcd_console_drawer::set_special_character(byte_t character_code, character_t character)
		{
			// Console doesn't support drawing custom characters
			return;
		}

		void lcd_console_drawer::draw_internal()
		{
			for (int y = 0; y < m_dimensions.height; ++y)
			{
				for (int x = 0; x < m_dimensions.width; ++x)
				{
					size_t position = convert_coordinate({ (byte_t)x, (byte_t)y });
					if (position > m_char_buffer.size())
						break;

					std::cout << m_char_buffer[position] << std::flush;
				}

				std::cout << std::endl;
			}
		}

		size_t lcd_console_drawer::convert_coordinate(position_t const& pos) const
		{
			return pos.y * m_dimensions.width + pos.x;
		}

		position_t lcd_console_drawer::convert_coordinate(size_t const& pos) const
		{
			return { pos % m_dimensions.width, (byte_t) (pos / m_dimensions.width) };
		}
	}
}*/