#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>

/* included all libraries that I might or might not need as a header file */

#define MAXSIZE 1024

/**
 * struct choices - has for purpose to choose the appropriate function
 * @choix: the keyword which will choose the function
 * @fp: The appropriate function
*/

typedef struct choices
{
	char *choix;
	int (*fp)(char **array);
} choice;

int _strchr(char *str, char chr);
char *_strcpy(char *first, char *second, int n);
int _strlen(char *s);
char *_strconcat(char *first, char *second, int n);
void _puts(char *chars);
int (*structchoice(char *command))(char **);
int _strcmp(char *first, char *second);
void freedouble(char **db);
void spacemv(char *str);
int argcount(char *line);
int childprocess(char *command, int count);
char *_getenv(char *var);
char *prepareforexec(char *command);
int _setenv(char *var, char *value, int signal);
int getexitcode(char *line);
int checkifcommandexists(char *line);
void _perror(char *argf, char *args);
int _getline(char **buffer, int *buffersize, int fd);
char *_strtok(char *line, char *delim);
void spacesback(char **args);
char *_calloc(int size);
int handleor(char *line);
void singinthandl(int s);
char *my_calloc(int size);

extern char **environ;
extern char *str_ptr;

int changedirectory(char **arguments);
int goout(char **arguments);
int getdir(char **arguments);
int setvar(char **arguments);
int deletvar(char **arguments);
int setals(char **arguments);
int deletals(char **arguments);
int notbuilt(char **arguments __attribute__((unused)));
void changeiffromparent(char *line);
char *goback(char *current);
void setvaratparent(char *line);
void deletvaratparent(char *line);
char *checkals(char *als);
void addquotes(char *arg);
char *itoa(int num);
char *convertvar(char *line);
char **handlechain(char *line);
int my_env(char **arguments);
void replace_environ();

#endif