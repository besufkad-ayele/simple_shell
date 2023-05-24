#include "shell.h"
/**
 * execute_proc - works in similar way as put in c language
 * @cmd: a pointer the integer we want to set to 402
 *	   some code we add that pass bettys requirment
 * Return: which will return some value 
 */
void execute_proc(char **cmd)
{

	char *parametro = (*(cmd + 1));
	char *s, *slash = "/";
	char *o;

	char *vartoprint = *cmd;
	char *argv[4];

	if ((access(cmd[0], F_OK) == 0))
	{
		argv[0] = cmd[0];
		argv[1] = parametro;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		o = find_command(vartoprint);

		slash = str_concat(o, slash);

		s = str_concat(slash, *cmd);

		argv[0] = s;
		argv[1] = parametro;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}

