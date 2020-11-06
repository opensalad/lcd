#include "stdafx.h"
#include "lcd.h"

namespace opensalad
{
	namespace lcd
	{
		lcd::lcd(std::shared_ptr<iface::i_lcd_drawer_interface> drawer_interface)
			: m_drawer_interface(drawer_interface)
		{
			init();
		}

		void lcd::send_command(byte_t const& cmd)
		{

		}

		void lcd::send_data(byte_t const& data)
		{

		}

		byte_t lcd::get_status()
		{
			return 0;
		}

		byte_t lcd::get_data()
		{
			return 0;
		}

		void lcd::init()
		{
			m_running_thread = std::thread{ std::bind(&lcd::run, this) };
		}

		void lcd::run()
		{
			m_drawer_interface->draw();
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
		}
	}
}