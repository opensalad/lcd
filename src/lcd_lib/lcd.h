#pragma once

#include <i_lcd_interface.h>
#include <i_lcd_draw_interface.h>
#include "observable_backlight_control.h"

namespace opensalad
{
	namespace lcd
	{
		class LCD_EXPORT lcd
			: public iface::i_lcd_interface
			, public iface::i_lcd_draw_interface
			, public observable_backlight_control
		{
		public:
			void send_command(byte_t const& cmd) override;
			void send_data(byte_t const& data) override;
			byte_t get_status() override;
			byte_t get_data() override;

			void draw() override;

		protected:
			dimensions_t get_screen_dimensions() const override;
			dimensions_t get_char_at(position_t const& position) const override;
		};
	}
}