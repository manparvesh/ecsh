/**
 * @file utils_test.c
 * @author manparvesh
 * @date 27th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <assert.h>
#include "../src/utils.h"

void test_line_split(){
    char *input_command = "split this line";
    char **arguments = split_line(input_command);
    int n = sizeof(arguments) / sizeof(arguments[0]);
    assert(n == 3);
}

//int main(){
//    test_line_split();
//}