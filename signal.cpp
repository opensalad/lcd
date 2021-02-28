#include "signal.h"

namespace opensalad
{
	namespace lcd
	{
		signal::signal(F func)
			: m_handler(func)
		{

		}

		void on_triggered(F func) override;
		void emit() override;
	}
}