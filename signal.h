#pragma once

#include <i_signal.h>

namespace opensalad
{
	namespace lcd
	{
		template <typename R, typename ...Args>
		class signal
			: public utils::i_signal<R(Args...)>
		{
		private:
			using F = R(Args...);

		public:
			signal(F func)
				: m_handler(func)
			{}

			void on_triggered(F func) override
			{
				m_handler = func;
			}

			void emit(Args... arg) override
			{
				m_handler(arg...);
			}

		private:
			F m_handler;
		};
	}
}