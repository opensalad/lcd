#pragma once

namespace lcd
{
    struct pin_props
    {
        std::string m_name;
        int m_index;
        int m_uuid;
        double m_analogValue;
        bool m_digitalValue;
    }
}