#include <stdafx.h>
#include "lcd.h"

namespace opensalad
{
	namespace lcd
	{
		lcd::lcd(std::shared_ptr<iface::i_lcd_drawer_interface> drawer_interface)
			: m_drawer_interface(drawer_interface)
			, m_cursor_position(0)
			, m_width(16)
			, m_height(4)
			, m_data_changed(true)
		{
			init();
		}

		void lcd::send_command(byte_t const& cmd)
		{

		}

		void lcd::send_data(byte_t const& data)
		{
			m_ddram[m_cursor_position++] = data;

			position_t pos = { (byte_t)(m_cursor_position % m_width), (byte_t)(m_cursor_position / m_width) };
			//m_drawer_interface->set_char_at(pos, data);
			m_data_changed = true;
		}

		byte_t lcd::get_status() const
		{
			return 0;
		}

		byte_t lcd::get_data() const
		{
			return 0;
		}

		void lcd::init()
		{
			m_ddram.resize(m_width * m_height, 0);
			//m_drawer_interface->set_dimension({ m_width, m_height });
			m_running_thread = std::thread{ std::bind(&lcd::run, this) };
		}

		void lcd::run()
		{
			if (m_data_changed)
			{
				//m_drawer_interface->draw();
				m_data_changed = false;
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
			}
		}
	}
}