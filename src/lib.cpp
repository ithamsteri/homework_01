#include "lib.hpp"
#include <sstream>

std::string say_hello(std::string& name) {
    std::ostringstream greeting_msg;
    
    greeting_msg << "Hello, " << name << '!';
    
    return greeting_msg.str();
}
