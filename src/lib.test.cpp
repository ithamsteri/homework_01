#include "lib.hpp"
#include <boost/test/minimal.hpp>

int test_main(int, char *[]) {
    std::string result {"Hello, World!"};
    
    return result.compare(say_hello("World")) != 0;
}
