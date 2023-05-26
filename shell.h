#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global environemnt */
extern char **environ;
/* Global program name */
char *name;
/* Global history counter */
int hist;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;rint_alias\
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_reallocate(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_directories(char *path);
int execute_inchild(char **args, char **front);
void free_list_t(list_t *head);
char *_itoa_integer_to_string(int num);

/* Input Helpers */
void handle_line(char **line, ssize_t read);
void var_replace(char **args, int *exe_ret);
char *get_arguments(char *line, int *exe_ret);
int call_arguments(char **args, char **front, int *exe_ret);
int run_arguments(char **args, char **front, int *exe_ret);
int handle_arguments(int *exe_ret);
int check_arguments(char **args);
void free_argumentsmemo(char **args, char **front);
char **replace_aliasesarg(char **args);

/* String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Builtins */
int (*get_builtins(char *command))(char **args, char **front);
int shellby_exitnormal(char **args, char **front);
int shellby_envcurrent(char **args, char __attribute__((__unused__)) **front);
int shellby_setenvcurrent(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenvcurrent(char **args, char __attribute__((__unused__)) **front);
int shellby_cdchanged(char **args, char __attribute__((__unused__)) **front);
int shellprint_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_helpinfo(char **args, char __attribute__((__unused__)) **front);

/* Builtin Helpers */
char **_shellby_creatcopyenv(void);
void free_env_copy(void);
char **_getenv_envpath(const char *var);

/* Error Handling */
int create_error(char **args, int err);
char *error_envshellby(char **args);
char *error_1_aliasbyvalue(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_126_permisiondenied(char **args);
char *error_127_commandnotfound(char **args);

/* Linkedlist Helpers */
alias_t *add_alias_t_end(alias_t **head, char *name, char *value);
void free_alias_t_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list_t(list_t *head);

void help_allcommands(void);
void help_aliascommands(void);
void help_cdcommands(void);
void help_exitcommands(void);
void help_helpcommands(void);
void help_envcommands(void);
void help_setenvcommands(void);
void help_unsetenvcommands(void);
void help_historycommands(void);

int proccess_file_commands(char *file_path, int *exe_ret);
#endif /*SHELL_H*/
