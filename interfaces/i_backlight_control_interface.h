#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_backlight_control_interface
			{
			public:
				virtual bool set_backlight_intencity(byte_t const& i) = 0;
				virtual byte_t get_backlight_intencity() const = 0;

				virtual bool set_backlight_color(
					byte_t const& r,
					byte_t const& g,
					byte_t const& b) = 0;
				virtual bool get_backlight_color(
					byte_t& r,
					byte_t& g,
					byte_t& b) const = 0;
				virtual bool is_backlight_color_supported() const = 0;
			};
		}
	}
}