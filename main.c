#include "shell.h"
/*
 * File: "main.c"
 * Author(s): Besufkad And Marsden
 */

/**
 * main -				Starts the shell CLI.
 * @argv:				Pointer to the first CLI arg.
 * @argc:				Number of CLI args (index starts at 1).
 * Return:				0 for success.
 */

int main(int argc, char **argv)
{
	(void)argc;

	return (start_shell(environ, argv[0]));
}
