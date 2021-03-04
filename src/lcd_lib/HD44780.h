#pragma once

#include <lcd_typedefs.h>
#include <lcd_export.h>
#include <interface/i_lcd_controller_interface.h>

namespace opensalad
{
    namespace lcd
    {
        class i_physical_interface;
        namespace iface
        {
            class i_lcd_drawer_interface;
        }

        class LCD_EXPORT HD44780
            : public iface::i_lcd_controller_interface
        {
        public:
            HD44780(std::shared_ptr<iface::i_lcd_drawer_interface> drawer);

            static byte_t const* get_char(char ch);

            virtual void send_command(byte_t const& cmd) override;
            virtual void send_data(byte_t const& data) override;
            virtual byte_t get_status() override;
            virtual byte_t get_data() override;

        private:
            void init();
            void run();

        private:
			std::shared_ptr<iface::i_lcd_drawer_interface> m_drawer_interface;
            std::weak_ptr<i_physical_interface> m_interface;
            std::array<byte_t, 80> m_ddram;
            std::array<byte_t, 64> m_cgram;

        public:
            static const std::array<const std::array<byte_t, 8>, 256> m_cgrom;

            std::thread m_running_thread;
            byte_t m_cursor_position;
            byte_t m_width;
            byte_t m_height;
            volatile bool m_data_changed;
        };
    }
}