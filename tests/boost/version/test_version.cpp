#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN // in only one cpp file
#include <boost/test/unit_test.hpp>
namespace bt = boost::unit_test;

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE( test_1_always_ok )
{
    BOOST_TEST( 1 == 1 );
}

BOOST_AUTO_TEST_SUITE_END()