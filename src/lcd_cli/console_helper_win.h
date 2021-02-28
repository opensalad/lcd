#pragma once

#include <windows.h>
#include "i_console_helper.h"

namespace opensalad
{
	namespace utils
	{
		class console_helper_win
			: public i_console_helper
		{
		public:
			static std::shared_ptr<i_console_helper> instance()
			{
				static std::shared_ptr<console_helper_win> i{ new console_helper_win{} };
				return i;
			}

		public:
			lcd::dimensions_t get_size() override
			{
				int columns, rows;
				columns = m_csbi.srWindow.Right - m_csbi.srWindow.Left + 1;
				rows = m_csbi.srWindow.Bottom - m_csbi.srWindow.Top + 1;
				return lcd::dimensions_t{ (lcd::byte_t)columns, (lcd::byte_t)rows };
			}

			lcd::position_t get_cursor_position() override
			{
				return lcd::position_t{ (lcd::byte_t)m_csbi.dwCursorPosition.X, (lcd::byte_t)m_csbi.dwCursorPosition.Y };
			}

		private:
			console_helper_win()
			{
				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &m_csbi);
			}
			CONSOLE_SCREEN_BUFFER_INFO m_csbi;
		};

		std::shared_ptr<i_console_helper> i_console_helper::get_platform_specific()
		{
			return console_helper_win::instance();
		}
	}
}