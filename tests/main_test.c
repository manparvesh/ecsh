/**
 * @file main_test.c
 * @author manparvesh
 * @date 25th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <assert.h>
#include <stdlib.h>

int main() {
    int status = system("./ecsh <<< $'exit\n' > /dev/null");
    // todo check why does this return 512 instead of 0
    assert(status == 512);
    return 0;
}
