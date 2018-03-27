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

//#define DEBUG

/**
 * Utility functions for Utilities..
 * */
int debug() {
#ifdef DEBUG
    return 1;
#else
    return 0;
#endif
}

void print_newline() {
    fputs("\n", stdout);
}

/**
 * Functions that will be used in the shell
 * */
void main_loop() {
    char *input_command;
    char **arguments;
    int status;

    while (TRUE) {
        // display prompt
        printf(ANSI_COLOR_YELLOW "ecsh> " ANSI_COLOR_RESET);

        // read and execute commands that were input and
        // exit if the user enters `exit`
        input_command = read_line();
        if (strncmp(input_command, "exit", 4) == 0) {
            break;
        }

        arguments = split_line(input_command);
        int length = sizeof(arguments) / sizeof(arguments[0]);
        if(debug()){
            for (int i = 0; i < length; ++i) {
                fputs(arguments[i], stdout);
                print_newline();
            }
        }
        status = execute(arguments);

        // cleanup
        free(arguments);
        free(input_command);
    }
}

int execute(char **arguments) {
    int i;
    if(arguments[0] == NULL){
        // empty command entered
        return 1;
    }

    // todo
    // here we check if there is a builtin function for the first argument
}

char **split_line(char *input_command) {
    int position = 0;
    char *token = NULL;
    int buffer_size = TOKEN_BUFFER_SIZE;
    char **tokens = malloc(buffer_size * sizeof(char *));

    int debug_mode = debug();
    if (debug_mode) {
        fputs("Input command:\t", stdout);
        fputs(input_command, stdout);
        print_newline();
    }

    if (!tokens) {
        printf("ecsh: token memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input_command, TOKEN_DELIMITERS);
    if (debug_mode) {
        fputs("Printing tokens:\n", stdout);
    }
    while (token != NULL) {
        tokens[position] = token;
        position++;
        if (debug_mode) {
            fputs(token, stdout);
            fputs("\n", stdout);
        }

        // if buffer size is exceeded, update size
        if (position >= buffer_size) {
            buffer_size += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, buffer_size * sizeof(char *));

            if (!tokens) {
                printf("ecsh: token memory allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        // move to next token
        token = strtok(NULL, TOKEN_DELIMITERS);
    }
    tokens[position] = NULL;
    if(debug_mode){
        char snum[3];
        sprintf(snum, "%d\n", position);
        fputs("Number of words in input: ", stdout);
        fputs(snum, stdout);
        print_newline();
    }
    return tokens;
}

char *read_line() {
    char *line = NULL;
    size_t buffer_size = 0;
    getline(&line, &buffer_size, stdin);
    return line;
}
