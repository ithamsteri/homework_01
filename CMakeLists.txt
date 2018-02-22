cmake_minimum_required(VERSION 3.2)

# check environment variable TRAVIS_BUILD_NUMBER
# TODO: better idea use git revision
if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD 0)
endif($ENV{TRAVIS_BUILD_NUMBER})

project(helloworld VERSION 1.0.${VERSION_BUILD})

# configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
# set variables in c++ header file for application
configure_file(version.hpp.in ${SOURCE_PATH}/version.hpp)

# make executable file for application
add_executable(helloworld_cli ${SOURCE_PATH}/main.cpp)
# and build own library
add_library(helloworld_lib ${SOURCE_PATH}/lib.cpp)

set_target_properties(helloworld_cli helloworld_lib PROPERTIES
    CXX_STANDART 14
    CXX_STANDART_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
    # INCLUDE_DIRECTORIES
)

# link executable file with libraries
target_link_libraries(helloworld_cli
    helloworld_lib
)