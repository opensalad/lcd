#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_drawer_interface
			{
			public:
				virtual ~i_lcd_drawer_interface() = default;
				virtual void draw() = 0;
			};
		}
	}
}