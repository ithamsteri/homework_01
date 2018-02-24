#include "lib.hpp"

#define BOOST_TEST_MODULE SimpleTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testSayHello)
{
    std::string result {"Hello, World!"};
    
    BOOST_CHECK_EQUAL(result.compare(say_hello("World")), 0);
}
