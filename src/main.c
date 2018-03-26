/**
 * @file main.c
 * @author manparvesh
 * @date 25th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <stdlib.h>
#include "utils.h"

int main(int argc, char const *argv[]) {
    main_loop();
    return EXIT_SUCCESS;
}
