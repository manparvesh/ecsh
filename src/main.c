#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//
// Created by manparvesh on 25/3/18.
//

#define TRUE 1
#define FALSE 0

void main_loop();

char *read_line();

int main(int argc, char const *argv[]) {
    main_loop();
    return EXIT_SUCCESS;
}

void main_loop() {
    while (TRUE) {
        printf("ecsh> ");
        char *input_command = read_line();
        if (strncmp(input_command, "exit", 4) == 0) {
            break;
        }
        fputs(input_command, stdout);
    }
}

char *read_line() {
    char *line = NULL;
    size_t buffer_size = 0;
    getline(&line, &buffer_size, stdin);
    return line;
}
