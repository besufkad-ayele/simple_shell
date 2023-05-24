#include "shell.h"

/**
 * start_shell -             Starts our loop looking for user's commands.
 * @environ:                 Array of environmental variables.
 * @exec_name:               Name of executable (name of our shell)
 * Return:                   0 on success, anything else on failure,
 *                           error code dependent.
 */
int do_shell_eof_or_newline(char *input, int bytes_read);
 
int start_shell(char **environ, char *exec_name)
{
	char *input = NULL;
	size_t input_buff_size = 0;
	ssize_t bytes_read = 0;
	sequence_t *com_q = NULL;
	his_q_t *his_q = NULL;

	/* attempt to register signal handlers and build history */
	if (register_signal_handlers() < 0)
		return (-1);
	
	while (1)
	{
		/* check if being used in interactive mode, if so: print */
		if (isatty(STDIN_FILENO))
			print_prompt();
		bytes_read = getline(&input, &input_buff_size, stdin);
		if (bytes_read <= 0 || input[0] == '\n')
		{
			/* EOF was received if return is 0 */
			if (!do_shell_eof_or_newline(input, bytes_read))
				return (0);
			continue;
		}
		fflush(stdin);
		/* attempt to parse the inputted line into a command queue */
		com_q = parse_string(input);
		if (!com_q)
			return (0);
		/* add the input to history & disgard b/c command Q built */
		if (input)
		{
			free(input);
			input = NULL;
		}
		/* attempt to execute the current command queue and move to */
		/* the next line after freeing the queue */
		if (execute_commands(his_q, com_q,
					environ, exec_name) < 0)
			return (-1);
		free_command_sequence(com_q);
	}
	return (0);
}

/**
 * do_shell_eof_or_newline - Decides if received input is EOF or \n
 * @input:                   Pointer to input string to be freed .
 *                           
 *                           so we must free.
 * @bytes_read:              Bytes read by getline(), used to determine if EOF.
 * Return:                   1 for newline was received, 0 for EOF was received
 */
int do_shell_eof_or_newline(char *input, int bytes_read)
{

	/* user pressed return, got new line, free input and continue */
	if (input)
	{
		free(input);
		input = NULL;
	}
	if (bytes_read <= 0)
	{
		if (isatty(STDIN_FILENO))
			print_newline();
		fflush(stdin);
		return (0); /* EOF received, exit shell */
	}
	return (1);
}

/**
 * print_prompt - prints the prompt for user to input command
 *
 * Return: always void.
 */
void print_prompt(void)
{
	write(STDOUT_FILENO, "$) ", 4);
}
