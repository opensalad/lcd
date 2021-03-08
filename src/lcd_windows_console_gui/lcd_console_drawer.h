#pragma once

#include <lcd_gui_export.h>
#include <i_lcd_drawer_interface.h>

namespace opensalad
{
	namespace lcd
	{
		namespace iface
		{
			class i_lcd_controller;
		}

		class LCD_GUI_EXPORT lcd_console_drawer
			: public iface::i_lcd_drawer_interface
			, public std::enable_shared_from_this<lcd_console_drawer>
		{
		public:
			lcd_console_drawer(int cols, int rows);
			virtual void draw() override;
			void setup();
			void run();

			std::weak_ptr<iface::i_lcd_controller> get_controller() const;

		private:
			void flush();
			char* pixel_pointer(int x, int y);
			char* char_at(int col, int row, int x, int y);
			void draw_character(int row, int col, uint8_t const* pixels);

			int screen_line_pixel_count() const;
			int screen_size_in_bytes() const;
			void set_colors() const;

		private:
			std::shared_ptr<iface::i_lcd_controller> m_controller;
			int m_rowsCount;
			int m_columnsCount;
			std::vector<char> m_screenBuffer;
			int m_bgColor;
			int m_fgColor;
		};
	}
}