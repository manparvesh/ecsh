/**
 * @file main.c
 * @author manparvesh
 * @date 25th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

int main(int argc, char const *argv[]) {
    printf("\e[1;1H\e[2J");
    printf("\n\t+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    printf(  "\t|                   ecsh                    |\n");
    printf(  "\t|-------------------------------------------|\n");
    printf(  "\t|            Licensed under MIT             |\n");
    printf(  "\t|-------------------------------------------|\n");
    printf(  "\t|              Use at own risk              |\n");
    printf(  "\t|-------------------------------------------|\n");
    printf(  "\t|     Author: Man Parvesh Singh Randhawa    |\n");
    printf(  "\t+-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-+\n");
    printf(  "\n\n");
    main_loop();
    return EXIT_SUCCESS;
}
