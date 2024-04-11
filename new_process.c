#include "simple.h"
#include <stdlib.h>


/**
 * npid - create a new process
 * for the child and the parent
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int npid(char **args)
{
	pid_t pid;
	int state;

	/* forking the parent id */
	pid = fork();
	if (pid ==  0)
	{
	/*checking for the child process */
		if (execvp(args[0], args) == -1)
		{
			perror("error in npid: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* checking for error during forking */
		perror("error in npid: forking");
	}
	else
	{
	/*checking for the parent process */
		do {
			waitpid(pid, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}
	return (-1);
}
