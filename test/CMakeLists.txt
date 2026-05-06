cmake_minimum_required(VERSION 3.16)
project(esp32_s3_ex2_tests CXX)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests
    test_uptime.cpp
    ../components/utils/uptime.cpp
)
target_include_directories(tests PRIVATE ../components/utils/include)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
