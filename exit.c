#include "shell.h"

/**
 * @his_q:	History queue to free.
 * @environ:	Array of pointers to environmental variables.
 * exit_shell -	Frees the queue and return exit code.
 * @seq:	Pointer to the sequence.
 * @status:	Exit code to exit with.
 * Return:	See macro values.
 */

void exit_shell(his_q_t *his_q, sequence_t *seq, int status, char **environ)
{
	free_command_sequence(seq);
	exit(status);
}
