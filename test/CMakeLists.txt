cmake_minimum_required(VERSION 3.16)
project(esp32_s3_ex2_tests CXX)

set(CMAKE_CXX_STANDARD 17)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

add_executable(tests
    test_uptime.cpp
    ../components/utils/uptime.cpp
)
target_include_directories(tests PRIVATE ../components/utils/include)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
