#pragma once

#include <i_lcd_drawer_interface.h>

namespace opensalad
{
	namespace lcd
	{
		class lcd_console_drawer
			: public iface::i_lcd_drawer_interface
			, public std::enable_shared_from_this<lcd_console_drawer>
		{
		public:
			lcd_console_drawer();
			virtual void draw(char* buffer, int width, int height) override;
			// virtual void set_char_at(position_t const& pos, byte_t character) override;
			// virtual void set_char_buffer(position_t const& pos, std::vector<byte_t> const& buffer) override;
			// virtual void set_pin_count(byte_t count) override;
			// virtual void set_pinout(std::vector<std::string> const& pinout) override;
			// virtual void set_dimension(dimensions_t screen_dimension) override;
			// virtual void set_backlight_intencity(byte_t backlight_intencity) override;
			// virtual void set_backlight_color(color_t backlight_color) override;
			// virtual void set_special_character(byte_t character_code, character_t character) override;

		private:
			void setup();
			void flush();
			char* pixel_pointer(int x, int y);
			char* char_at(int col, int row, int x, int y);
			void draw_character(int row, int col, uint8_t const* pixels);

		private:


			// std::vector<byte_t> m_char_buffer;
			// byte_t m_pin_count;
			// std::vector<std::string> m_pinout_naming;
			// dimensions_t m_dimensions;
			// byte_t m_backlight_intencity;
			// color_t m_backlight_color;
			// position_t m_console_cursor_position;
		};
	}
}