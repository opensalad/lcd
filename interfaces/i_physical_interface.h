#pragma once

#include <lcd_export.h>

namespace lcd
{
    class LCD_EXPORT i_physical_interface
    {
    public:
        virtual ~i_physical_interface() = default;

        virtual void pulse_up(int pin_id) = 0;
        virtual void pulse_down(int pin_id) = 0;
        virtual void edge_up(int pin_id) = 0;
        virtual void edge_down(int pin_id) = 0;

        virtual double read_analog(int pin_id) = 0;
        virtual void write_analog(int pin_id, double value) = 0;

        virtual bool read_digital(int pin_id) = 0;
        virtual void write_digital(int pin_id, bool value) = 0;
    };
}