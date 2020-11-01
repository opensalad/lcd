#include "stdafx.h"
#include "simple_backlight_control.h"

namespace opensalad
{
	namespace lcd
	{
		simple_backlight_control::simple_backlight_control()
			: m_intencity(128)
		{

		}

		bool simple_backlight_control::set_backlight_intencity(byte_t const& i)
		{
			if (m_intencity == i)
				return false;

			m_intencity = i;
			return true;
		}

		byte_t simple_backlight_control::get_backlight_intencity() const
		{
			return m_intencity;
		}

		bool simple_backlight_control::set_backlight_color(byte_t const& r, byte_t const& g, byte_t const& b)
		{
			return is_backlight_color_supported();
		}

		bool simple_backlight_control::get_backlight_color(byte_t& r, byte_t& g, byte_t& b) const
		{
			return is_backlight_color_supported();
		}

		bool simple_backlight_control::is_backlight_color_supported() const
		{
			return false;
		}
	}
}