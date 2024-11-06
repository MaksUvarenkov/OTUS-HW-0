#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN // in only one cpp file
#include <boost/test/unit_test.hpp>
namespace bt = boost::unit_test;

BOOST_AUTO_TEST_CASE( test1 )
{
    // reports 'error in "test1": test 2 == 1 failed'
    BOOST_TEST( 2 == 1 );
}