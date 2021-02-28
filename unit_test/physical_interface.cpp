#define BOOST_TEST_MODULE PhysicalInterface
#include <boost/test/unit_test.hpp>
#include <lcd_lib/abstract_physical_interface.h>

namespace utf = boost::unit_test;

#define TEST_PINOUT( iface, v0, v1, v2, v3, v4 ) \
    BOOST_CHECK_EQUAL( iface .read_analog(0), v0); \
    BOOST_CHECK_EQUAL( iface .read_analog(1), v1); \
    BOOST_CHECK_EQUAL( iface .read_analog(2), v2); \
    BOOST_CHECK_EQUAL( iface .read_analog(3), v3); \
    BOOST_CHECK_EQUAL( iface .read_analog(4), v4);

#define TEST_PINOUT_DIGITAL( iface, v0, v1, v2, v3, v4 ) \
    BOOST_CHECK_EQUAL( iface .read_digital(0), v0); \
    BOOST_CHECK_EQUAL( iface .read_digital(1), v1); \
    BOOST_CHECK_EQUAL( iface .read_digital(2), v2); \
    BOOST_CHECK_EQUAL( iface .read_digital(3), v3); \
    BOOST_CHECK_EQUAL( iface .read_digital(4), v4);


BOOST_AUTO_TEST_CASE(physical_interface, *utf::tolerance(0.00001))
{
    lcd::abstract_physical_interface interface(5);

    TEST_PINOUT(interface, 0.0, 0.0, 0.0, 0.0, 0.0);
    interface.edge_up(0);
    interface.edge_up(2);
    TEST_PINOUT(interface, 5.0, 0.0, 5.0, 0.0, 0.0);
    interface.edge_down(0);
    interface.edge_down(2);
    interface.edge_up(1);
    interface.edge_up(3);
    TEST_PINOUT_DIGITAL(interface, false, true, false, true, false);
}