#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_controller_interface
			{
			public:
				virtual ~i_lcd_controller_interface() = default;

				virtual void send_command(byte_t const& cmd) = 0;
				virtual void send_data(byte_t const& data) = 0;
				virtual byte_t get_status() = 0;
				virtual byte_t get_data() = 0;
			};
		}
	}
}