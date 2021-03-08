#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_controller
			{
			public:
				virtual ~i_lcd_controller() = default;

				virtual void send_command(byte_t const& cmd) = 0;
				virtual void send_data(byte_t const& data) = 0;
				virtual byte_t get_status() const = 0;
				virtual byte_t get_data() const = 0;
			};
		}
	}
}