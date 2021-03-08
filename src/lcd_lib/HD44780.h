#pragma once

#include <lcd_typedefs.h>
#include <lcd_export.h>
#include <i_lcd_controller.h>
#include <i_lcd_controller_simplified.h>

namespace opensalad
{
    namespace lcd
    {
        class i_physical_interface;

        class LCD_EXPORT HD44780
            : public iface::i_lcd_controller
            , public iface::i_lcd_controller_simplified
        {
        public:
            HD44780();

            static byte_t const* get_char(char ch);

            virtual void send_command(byte_t const& cmd) override;
            virtual void send_data(byte_t const& data) override;
            virtual byte_t get_status() const override;
            virtual byte_t get_data() const override;

            virtual void set_light_intencity(double const& intencity) override;
            virtual double get_light_intencity() const override;

            virtual display_line_mode line_mode() const override;
            virtual void set_line_mode(display_line_mode line_mode) override;

            virtual byte_t const* get_character_at(int ddram_address) const override;

        private:
            static const std::array<const std::array<byte_t, 8>, 256> s_cgrom;
            std::weak_ptr<i_physical_interface> m_interface;
            std::array<byte_t, 80> m_ddram;
            std::array<byte_t, 64> m_cgram;

            int m_ddram_shift;
            double m_lightIntencity;
            uint8_t m_increment;

            uint8_t m_addressCounter;

            i_lcd_controller_simplified::display_line_mode m_lineMode;
        };
    }
}