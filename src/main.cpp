#include "lib.hpp"
#include "version.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    // show greeting message
    std::cout << say_hello(std::move("World"))<< std::endl;
}
