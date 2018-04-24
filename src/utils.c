/**
 * @file utils.c
 * @author manparvesh
 * @date 27th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <values.h>
#include "utils.h"

/*
  Function Declarations for builtin shell commands:
 */
int ecsh_cd(char **args);

int ecsh_help(char **args);

int ecsh_exit(char **args);

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_strings[] = {
        "cd",
        "help",
        "exit"
};

int (*builtin_function[])(char **) = {
        &ecsh_cd,
        &ecsh_help,
        &ecsh_exit
};

int process_input(char *input_command);

int ecsh_num_builtins() {
    return sizeof(builtin_strings) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int ecsh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "ecsh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("ecsh");
        }
    }
    return EXIT_SUCCESS;
}

int ecsh_help(char **args) {
    int i;
    printf("Man Parvesh Singh Randhawa's ecsh\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following commands are built in:\n");

    for (i = 0; i < ecsh_num_builtins(); i++) {
        printf("  %s\n", builtin_strings[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return EXIT_SUCCESS;
}

int ecsh_exit(char **args) {
    printf(ANSI_COLOR_RED "Goodbye..\n" ANSI_COLOR_RESET);
    return 13;
}

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
    int status = 0;

    while (status != 13) {
        // display prompt
        char hostname[HOST_NAME_MAX];
        char username[LOGIN_NAME_MAX];
            gethostname(hostname, HOST_NAME_MAX);
        getlogin_r(username, LOGIN_NAME_MAX);
        printf(ANSI_BOLD_GREEN "%s@%s" ANSI_COLOR_RESET, username, hostname);

        printf(":");

        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf(ANSI_BOLD_BLUE "%s " ANSI_COLOR_RESET, cwd);
        }
        printf(ANSI_BOLD_YELLOW "ecsh> %s  " ANSI_COLOR_RESET, status == 0 ? "OK" : "NG");

        // read and execute commands that were input and
        // exit if the user enters `exit`
        input_command = read_line();

        status = process_input(input_command);

        if (debug()) {
            printf("Status code received: %d\n", status);
        }

        // cleanup
        free(input_command);
    }
}

// function for finding pipe
int parse_pipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL)
            break;
    }

    if (strpiped[1] == NULL)
        return FALSE; // returns false if no pipe is found.
    else {
        return TRUE;
    }
}

int process_input(char *input_command) {
    char **arguments;
    char* strpiped[2];
    int piped = FALSE;

    piped = parse_pipe(input_command, strpiped);

    if (piped == TRUE) {
        printf("Piping is added!\n");
        // todo implement this part
    } else {
        arguments = split_line(input_command);
        int length = sizeof(arguments) / sizeof(arguments[0]);
        if (debug()) {
            for (int i = 0; i < length; ++i) {
                fputs(arguments[i], stdout);
                print_newline();
            }
        }
        return execute(arguments);
    }
}

int launch(char **arguments) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // child process
        // execvp checks if the argument is present in the `PATH` env variable and tries to run it.
        if (execvp(arguments[0], arguments) == -1) {
            perror("ecsh");
        }
        free(arguments);
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        // error in forking
        perror("ecsh: error in forking");
    } else {
        // parent
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(arguments);
    return EXIT_SUCCESS;
}

int execute(char **arguments) {
    int i;
    if (arguments[0] == NULL) {
        // empty command entered
        return EXIT_FAILURE;
    }

    // here we check if there is a builtin function for the first argument
    for (i = 0; i < ecsh_num_builtins(); i++) {
        if (strcmp(arguments[0], builtin_strings[i]) == 0) {
            return (*builtin_function[i])(arguments);
        }
    }

    return launch(arguments);
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
    if (debug_mode) {
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
