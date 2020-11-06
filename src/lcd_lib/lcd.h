#pragma once

#include <i_lcd_interface.h>
#include <i_lcd_drawer_interface.h>
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
			lcd(std::shared_ptr<iface::i_lcd_drawer_interface> drawer_interface);

			void send_command(byte_t const& cmd) override;
			void send_data(byte_t const& data) override;
			byte_t get_status() override;
			byte_t get_data() override;

		private:
			void init();
			void run();

		private:
			std::shared_ptr<iface::i_lcd_drawer_interface> m_drawer_interface;
			std::thread m_running_thread;
		};
	}
}