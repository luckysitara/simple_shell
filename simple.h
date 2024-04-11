#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

void interactive(void);
void non_interactive(void);

char *readlf(void);
char **sptlf(char *line);
int get_execute(char **args);
char *get_stream(void);

int npid(char **args);
char *get_line(void);

int my_cd(char **args);
int myget_exit(char **args);
int my_env(char **args);
int my_help(char **args);

#endif
