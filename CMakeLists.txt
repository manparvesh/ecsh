cmake_minimum_required(VERSION 3.9)
project(ecsh)

set(CMAKE_CXX_STANDARD 17)

add_executable(ecsh
        src/main.c src/utils.c src/utils.h)

enable_testing()

set(TEST_EXE_NAME ecsh_tests)

add_executable(${TEST_EXE_NAME}
        tests/main_test.c tests/utils_test.c)

add_test(NAME "ECSH_TESTS"
        COMMAND ${TEST_EXE_NAME})