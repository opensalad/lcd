#pragma once

#include <lcd_export.h>
#include <i_lcd_controller.h>
#include <i_lcd_drawer_interface.h>
#include "observable_backlight_control.h"
#include "signal.h"

namespace opensalad
{
	namespace lcd
	{
		class LCD_EXPORT lcd
			: public iface::i_lcd_controller
			, public observable_backlight_control
		{
		public:
			lcd(std::shared_ptr<iface::i_lcd_drawer_interface> drawer_interface);

			void send_command(byte_t const& cmd) override;
			void send_data(byte_t const& data) override;
			byte_t get_status() const override;
			byte_t get_data() const override;

		private:
			void init();
			void run();

		private:
			std::shared_ptr<iface::i_lcd_drawer_interface> m_drawer_interface;
			std::thread m_running_thread;
			std::vector<byte_t> m_ddram;
			byte_t m_cursor_position;
			byte_t m_width;
			byte_t m_height;
			volatile bool m_data_changed;
		};
	}
}