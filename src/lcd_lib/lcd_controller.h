#pragma once

namespace lcd
{
    class i_physical_interface;

    class HD44780
    {
    public:
        HD44780();

    private:
        std::weak_ptr<i_physical_interface> m_interface;
        std::array<uint8_t, 80> m_ddram;
        std::array<uint8_t, 64> m_cgram;
    };
}