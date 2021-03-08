#pragma once

#include <lcd_export.h>

namespace lcd
{
    class LCD_EXPORT i_pin
    {
    public:
        virtual ~i_pin() = default;

        virtual void set_value(double value) = 0;
        virtual double get_value() const = 0;
    };
}