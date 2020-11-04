#include "stdafx.h"
#include "lcd.h"

namespace opensalad
{
	namespace lcd
	{
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

		void lcd::draw()
		{

		}

		dimensions_t lcd::get_screen_dimensions() const
		{
			return dimensions_t{};
		}

		dimensions_t lcd::get_char_at(position_t const& position) const
		{
			return dimensions_t{};
		}
	}
}