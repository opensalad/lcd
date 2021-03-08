#pragma once

#include <lcd_export.h>
#include <i_pin.h>

namespace lcd
{
    class LCD_EXPORT abstract_analog_pin
        : public i_pin
    {
    public:
        abstract_analog_pin(std::string const& name = "");
        virtual void set_value(double value) override;
        virtual double get_value() const override;

    private:
        std::string m_name;
        double m_currentValue;
    };
}