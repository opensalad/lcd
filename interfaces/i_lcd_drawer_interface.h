#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_drawer_interface
			{
			public:
				virtual ~i_lcd_drawer_interface() = default;
				virtual void draw() = 0;
				virtual void set_char_at(position_t const& pos, byte_t character) = 0;
				virtual void set_char_buffer(position_t const& pos, std::vector<byte_t> const& buffer) = 0;
				virtual void set_pin_count(byte_t count) = 0;
				virtual void set_pinout(std::vector<std::string> const& pinout) = 0;
				virtual void set_dimension(dimensions_t screen_dimension) = 0;
				virtual void set_backlight(byte_t backlight) = 0;
				virtual void set_backlight_color(color_t backlight_color) = 0;
				virtual void set_special_character(byte_t character_code, character_t character) = 0;
			};
		}
	}
}