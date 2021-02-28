#pragma once

#include <lcd_export.h>
#include <lcd_lib/interface/i_pin_provider.h>

namespace lcd
{
    class i_pin;

    class LCD_EXPORT abstract_pin_provider
        : public i_pin_provider
    {
    public:
        abstract_pin_provider(int pin_count);
        virtual std::weak_ptr<i_pin> get_pin(int pin_id) override;

    private:
        std::vector<std::shared_ptr<i_pin>> m_pinout;
    };
}