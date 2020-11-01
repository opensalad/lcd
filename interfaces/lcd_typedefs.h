#pragma once

namespace opensalad
{
	namespace lcd
	{
		using byte_t = uint8_t;
		using color_t = struct
		{
			byte_t red;
			byte_t green;
			byte_t blue;
		};
	}
}