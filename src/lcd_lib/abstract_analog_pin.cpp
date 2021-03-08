#include <stdafx.h>

#include "abstract_analog_pin.h"

namespace lcd
{
    abstract_analog_pin::abstract_analog_pin(std::string const& name)
        : m_name(name)
        , m_currentValue(0.0)
    {}

    void abstract_analog_pin::set_value(double value)
    {
        m_currentValue = value;
    }

    double abstract_analog_pin::get_value() const
    {
        return m_currentValue;
    }
}