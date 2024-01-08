#ifndef SHELL_H
#define SHELL_H
#define DEL " \n\t\a\r\""
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
int str_length(char *text);
int str_compare(char *str1, char *str2);
char *_str_dup(char *str);
char *_str_copy(char *str1, char *str2);
char *_str_concat(char *str1, char *str2);
char *_get_env(char *name);
void env_command(void);
extern char **environ;
int _atoi(char *str);
char *print_num(int n);
void non_inter(char **argv);
void inter(char **argv);
char *excable(char *l);
char *handle_line(char *line);
int builtinOrNo(char *line, char *prog, int count, char *ml,  int *status);
int _exit_(char *line, char *prog, int count, char *ml, int *status);
void _error_(int count, char *prog, int status, char *line);
void errorExit(char *line, char *c, char *prog);
void errorcmd(char *line, char *c, char *prog);
void errorPath(char *line, char *c, char *prog);
char **cmdAfter(char *line);
int excute(char *cmd, char **argv, char *environment[],int *status);
void excute_sec_case(char *cmd, char **argv, char *environment[], int *status);
#endif
