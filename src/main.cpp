#include "lib.hpp"
#include "version.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    std::string name {"World"};
    
    // show greeting message
    std::cout << say_hello(name)<< std::endl;
}
