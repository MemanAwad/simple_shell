#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;
/*==============SHELLL===============*/

void intershell(int ac, char **av);
void nointershell(int ac, char **av);
char *getstring(void);

/*==============PATH FUNCTIONS===============*/
char *_getenv(char *variable);
char *getpathvalue(char *path, char *a);
int commands(char *cmd);

/*===================HANDLE==================*/

char *getcmd(char *str);
int parsecmd(char *str, char *command);
void handle_command(char *str, char *delm);
void handle_command2(char *str, char *s, char *arg);
int tok_nums(char *str, char *delm);
char **_tok(char *str, char *delm, int num);
int _fork(char *cmd, char **arg);
void freeEnv(char **env);
void tokens(char *str);
void errmsg(char *str);
int handle_cd2(char *str);


/*==============BUILT_IN=====================*/

void exitshell(int status);
int handle_exit(char *command, char *str, int n);
int check(char *str);
void _env(void);
int handle_cd(char *command, char *path, int n);
int _cd(char *path);

/*============STRING FUNCTIONS===============*/

int _atoi(const char *str);
char *_strchr(const char *str, int c);
char *_strtok(char *string, const char *delim);
int isdelim(const char *delim, char c);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char *_strcat(char *dest, char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

/*=================END=====================*/

#endif
