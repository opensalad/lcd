#pragma once

#include <lcd_export.h>

namespace lcd
{
    class i_pin;

    class LCD_EXPORT i_pin_provider
    {
    public:
        virtual ~i_pin_provider() = default;

        virtual std::weak_ptr<i_pin> get_pin(int pin_id) = 0;
    };
}