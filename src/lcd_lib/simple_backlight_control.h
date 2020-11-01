#pragma once

#include <i_backlight_control_interface.h>

namespace opensalad
{
	namespace lcd
	{
		class simple_backlight_control : public iface::i_backlight_control_interface
		{
		public:
			simple_backlight_control();
			void set_backlight_intencity(byte_t const& i) override;
			byte_t set_backlight_intencity() const override;

			bool set_backlight_color(byte_t const& r, byte_t const& g, byte_t const& b) override;
			bool get_backlight_color(byte_t& r, byte_t& g, byte_t& b) const override;
			bool is_backlight_color_supported() const override;

		private:
			byte_t m_intencity;
		};
	}
}