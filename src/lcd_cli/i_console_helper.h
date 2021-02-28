#pragma once

namespace opensalad
{
	namespace utils
	{
		class i_console_helper
		{
		public:
			static std::shared_ptr<i_console_helper> get_platform_specific();

		public:
			virtual ~i_console_helper() = default;
			virtual lcd::dimensions_t get_size() = 0;
			virtual lcd::position_t get_cursor_position() = 0;
		};
	}
}