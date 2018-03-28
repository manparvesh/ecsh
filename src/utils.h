/**
 * @file utils.h
 * @author manparvesh
 * @date 27th March, 2018
 * @brief ecsh (elementary shell that is also a C interpreter)
 * */


#ifndef ECSH_UTILS_H
#define ECSH_UTILS_H

#define TRUE 1
#define FALSE 0
#define TOKEN_DELIMITERS " \t\r\n\a"
#define TOKEN_BUFFER_SIZE 64

// these will be used for colored output
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD_BLACK   "\033[1m\033[30m"
#define ANSI_BOLD_RED     "\033[1m\033[31m"
#define ANSI_BOLD_GREEN   "\033[1m\033[32m"
#define ANSI_BOLD_YELLOW  "\033[1m\033[33m"
#define ANSI_BOLD_BLUE    "\033[1m\033[34m"
#define ANSI_BOLD_MAGENTA "\033[1m\033[35m"
#define ANSI_BOLD_CYAN    "\033[1m\033[36m"
#define ANSI_BOLD_WHITE   "\033[1m\033[37m"

void main_loop();

char *read_line();

char **split_line(char *input_command);

int execute(char **arguments);

#endif //ECSH_UTILS_H
