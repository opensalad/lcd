#pragma once

#include <i_observable_backlight_control_interface.h>
#include <observable_property.h>

namespace opensalad
{
	namespace lcd
	{
		class observable_backlight_control
			: public iface::i_observable_backlight_control_interface
		{
		public:
			observable_backlight_control();

			bool set_backlight_intencity(byte_t const& i) override;
			byte_t get_backlight_intencity() const override;

			bool set_backlight_color(
				byte_t const& r,
				byte_t const& g,
				byte_t const& b) override;
			bool get_backlight_color(
				byte_t& r,
				byte_t& g,
				byte_t& b) const override;
			bool is_backlight_color_supported() const override;

			void on_backlight_intencity_changed(std::function<void()> const& cb) override;
			void on_backlight_color_changed(std::function<void()> const& cb) override;

		private:
			utils::observable_property<byte_t> m_intencity;
			utils::observable_property<color_t> m_color;
		};
	}
}