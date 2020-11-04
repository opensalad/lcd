#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_draw_interface
			{
			public:
				virtual ~i_lcd_draw_interface() = default;
				virtual void draw() = 0;

			protected:
				virtual dimensions_t get_screen_dimensions() const = 0;
				virtual dimensions_t get_char_at(position_t const& position) const = 0;
			};
		}
	}
}