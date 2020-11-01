#pragma once

#include <i_backlight_control_interface.h>
#include <i_observable.h>

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_observable_backlight_control_interface
				: i_backlight_control_interface
			{
				virtual void on_backlight_intencity_changed(std::function<void()> const& cb) = 0;
				virtual void on_backlight_color_changed(std::function<void()> const& cb) = 0;
			};
		}
	}
}