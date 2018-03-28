cmake_minimum_required(VERSION 3.9)
project(ecsh)

add_executable(ecsh
        src/main.c src/utils.c src/utils.h)

enable_testing()

# test that checks if the shell starts properly
set(COMMON_TEST_EXE_NAME ecsh_main_test)
add_executable(${COMMON_TEST_EXE_NAME}
        tests/main_test.c)
add_test(NAME "ecsh_main_test"
        COMMAND ${COMMON_TEST_EXE_NAME})

# test that checks the utility functions that are implemented
set(UTIL_TEST_EXE_NAME ecsh_util_tests)
add_executable(${UTIL_TEST_EXE_NAME}
        tests/utils_test.c)
add_test(NAME "ecsh_util_tests"
        COMMAND ${UTIL_TEST_EXE_NAME})

set_property(TARGET ecsh PROPERTY C_STANDARD 99)
set_property(TARGET ecsh_main_test PROPERTY C_STANDARD 99)
set_property(TARGET ecsh_util_tests PROPERTY C_STANDARD 99)
