#include "abstract_physical_interface.h"

#include "abstract_pin_provider.h"
#include <lcd_lib/interface/i_pin.h>

namespace lcd
{
    namespace
    {
        constexpr static std::chrono::duration pulse_duration = std::chrono::microseconds(100);
        constexpr static double digital_signal_low = 0;
        constexpr static double digital_signal_high = 5;
        constexpr static double digital_signal_low_treshold = 2.4;
    }

    abstract_physical_interface::abstract_physical_interface(int pin_count)
        : m_pinProvider(std::make_unique<abstract_pin_provider>(pin_count))
    {}

    void abstract_physical_interface::pulse_up(int pin_id)
    {
        edge_up(pin_id);
        std::this_thread::sleep_for(pulse_duration);
        edge_down(pin_id);
    }

    void abstract_physical_interface::pulse_down(int pin_id)
    {
        edge_down(pin_id);
        std::this_thread::sleep_for(pulse_duration);
        edge_up(pin_id);
    }

    void abstract_physical_interface::edge_up(int pin_id)
    {
        write_digital(pin_id, true);
    }

    void abstract_physical_interface::edge_down(int pin_id)
    {
        write_digital(pin_id, false);
    }

    double abstract_physical_interface::read_analog(int pin_id)
    {
        auto wpin = m_pinProvider->get_pin(pin_id);
        auto spin = wpin.lock();
        if (!spin)
            return NAN;

        return spin->get_value();
    }

    void abstract_physical_interface::write_analog(int pin_id, double value)
    {
        auto wpin = m_pinProvider->get_pin(pin_id);
        auto spin = wpin.lock();
        if (!spin)
            return;

        spin->set_value(value);
    }

    bool abstract_physical_interface::read_digital(int pin_id)
    {
        return read_analog(pin_id) > digital_signal_low_treshold;
    }

    void abstract_physical_interface::write_digital(int pin_id, bool value)
    {
        write_analog(pin_id, value ? digital_signal_high : digital_signal_low);
    }
}