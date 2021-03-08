#pragma once

#include <lcd_export.h>
#include <i_physical_interface.h>
#include <i_pin_provider.h>

namespace lcd
{
    class LCD_EXPORT abstract_physical_interface
        : public i_physical_interface
    {
    public:
        abstract_physical_interface(int pin_count);

        virtual void pulse_up(int pin_id) override;
        virtual void pulse_down(int pin_id) override;
        virtual void edge_up(int pin_id) override;
        virtual void edge_down(int pin_id) override;

        virtual double read_analog(int pin_id) override;
        virtual void write_analog(int pin_id, double value) override;

        virtual bool read_digital(int pin_id) override;
        virtual void write_digital(int pin_id, bool value) override;

    private:
        std::unique_ptr<i_pin_provider> m_pinProvider;
    };
}