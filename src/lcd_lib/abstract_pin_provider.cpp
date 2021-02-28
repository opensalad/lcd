#include "abstract_pin_provider.h"

#include "abstract_analog_pin.h"

namespace lcd
{
    abstract_pin_provider::abstract_pin_provider(int pin_count)
        : m_pinout()
    {
        m_pinout.reserve(pin_count);
        for(int i = 0; i < pin_count; ++i)
        {
            m_pinout.push_back(std::make_shared<abstract_analog_pin>());
        }
    }

    std::weak_ptr<i_pin> abstract_pin_provider::get_pin(int pin_id)
    {
        return m_pinout[pin_id];
    }
}