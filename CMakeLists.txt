cmake_minimum_required(VERSION 3.2)

# check environment variable TRAVIS_BUILD_NUMBER
# TODO: better idea use git revision
if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_BUILD $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(VERSION_BUILD 0)
endif()

project(helloworld VERSION 1.0.${VERSION_BUILD})

# we need boost for unit test
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
# set variables in c++ header file for application
configure_file(version.hpp.in ${SOURCE_PATH}/version.hpp)

# make executable file for application
add_executable(helloworld_cli ${SOURCE_PATH}/main.cpp)
add_executable(unit_test ${SOURCE_PATH}/lib.test.cpp)
# and build own library
add_library(helloworld_lib ${SOURCE_PATH}/lib.cpp)

set_target_properties(helloworld_cli helloworld_lib unit_test PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS -Wpedantic -Wall -Wextra
    # INCLUDE_DIRECTORIES
)

# link executable file with libraries
target_link_libraries(helloworld_cli
    helloworld_lib
)

target_link_libraries(unit_test
    ${Boost_LIBRARIES}
    helloworld_lib
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT alex.aspirine@gmail.com)

include(CPack)

enable_testing()

#tests-> test_name   target_name
add_test(simple_test unit_test)
