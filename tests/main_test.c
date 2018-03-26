/**
 * @file main_test.c
 * @author manparvesh
 * @date 25th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <assert.h>
#include <stdlib.h>

int test_main() {
    int status = system("./ecsh > /dev/null");
    assert(status == 0);
    return 0;
}
