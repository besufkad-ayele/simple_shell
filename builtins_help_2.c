#include "shell.h"

void help_envcommands(void);
void help_setenvcommands(void);
void help_unsetenvcommands(void);
void help_historycommands(void);

/**
 * help_envcommands - Displays information on the shellby builtin command 'env'.
 */
void help_envcommands(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenvcommands - Displays information on the shellby builtin command 'setenv'.
 */
void help_setenvcommands(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenvcommands - Displays information on the shellby builtin command
 * 'unsetenv'.
 */
void help_unsetenvcommands(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
