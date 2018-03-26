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

void main_loop();

char *read_line();

char **split_line(char *input_command);

int execute(char **arguments);

#endif //ECSH_UTILS_H
