#include "shell.h"

/**
 * prompt - call prompt from another function (prompt)
 *
 **/
void prompt(void)
{
	for (;;)
	{
		char *text = NULL;
		pid_t child_pid;
		int status, lenbuf;
		size_t bufsize = 0;

		place("$) ");
		lenbuf = getline(&text, &bufsize, stdin);
		if (lenbuf == -1)
			exit(98);
		if (compareExit(text, "exit") == 0){
			char *arg = strtok(text, " ");
			arg = strtok(NULL, " ");
			if (arg != NULL) {
				int exit_status = atoi(arg);
				exit(exit_status);
			}
			}
		
		child_pid = fork();
		if (child_pid < 0)
			perror("Error(");
		if (child_pid == 0)
			identify_string(text);
		else
			wait(&status);
	}}
