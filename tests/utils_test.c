/**
 * @file utils_test.c
 * @author manparvesh
 * @date 27th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <assert.h>
#include "../src/utils.c"

void test_line_split() {
    char input_command[] = "split this line";
    fputs(input_command, stdout);
    char **arguments;
    arguments = split_line(input_command);
    int i;
    for (i = 0; i < 3; i++) {
        assert(strlen(arguments[i]));
    }
}

int main() {
    test_line_split();
}