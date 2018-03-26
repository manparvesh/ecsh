/**
 * @file utils.c
 * @author manparvesh
 * @date 27th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "utils.h"

void main_loop() {
    char *input_command;
    char **arguments;
    int status;

    while (TRUE) {
        // display prompt
        printf("ecsh> ");

        // read and execute commands that were input and
        // exit if the user enters `exit`
        input_command = read_line();
        if (strncmp(input_command, "exit", 4) == 0) {
            break;
        }

        arguments = split_line(input_command);
        status = execute(arguments);

        // cleanup
        free(arguments);
        free(input_command);
        // fputs(input_command, stdout);
    }
}

int execute(char **arguments) {
    return 0;
}

char **split_line(char *input_command) {
    int position = 0;
    char *token = NULL;
    char **tokens = malloc(TOKEN_BUFFER_SIZE * sizeof(char *));
    int buffer_size = TOKEN_BUFFER_SIZE;

    token = strtok(input_command, TOKEN_DELIMITERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        // if buffer size is exceeded, update size
        if (position == buffer_size) {
            buffer_size += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));

            if (!tokens) {
                printf("ecsh: token memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        // move to next token
        token = strtok(input_command, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    return tokens;
}

char *read_line() {
    char *line = NULL;
    size_t buffer_size = 0;
    getline(&line, &buffer_size, stdin);
    return line;
}
