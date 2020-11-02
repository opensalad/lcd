#pragma once

#include <i_lcd_interface.h>
#include "observable_backlight_control.h"

namespace opensalad
{
	namespace lcd
	{
		class LCD_EXPORT lcd
			: public iface::i_lcd_interface
			, public observable_backlight_control
		{
		public:
			void send_command(byte_t const& cmd) override;
			void send_data(byte_t const& data) override;
		};
	}
}