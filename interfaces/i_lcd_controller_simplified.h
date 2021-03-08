#pragma once

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_controller_simplified
			{
			public:
				enum class display_line_mode
				{
					single_line,
					double_line
				};

			public:
				virtual ~i_lcd_controller_simplified() = default;

				virtual void set_light_intencity(double const& intencity) = 0;
				virtual double get_light_intencity() const = 0;

				virtual display_line_mode line_mode() const = 0;
				virtual void set_line_mode(display_line_mode line_mode) = 0;

				virtual byte_t const* get_character_at(int ddram_address) const = 0;
			};
		}
	}
}