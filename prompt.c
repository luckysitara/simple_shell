#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("emmy\'s_shell$ ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
		printf("\n");
		break;
		/* Handle end of file (Ctrl+D)*/
	}

	command[strcspn(command, "\n")] = '\0';
	/* Remove the newline character*/

        /* Fork a child process*/
	pid_t child_pid = fork();

	if (child_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
/* Child process, execute the command*/
		if (execlp(command, command, NULL) == -1)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
/* Parent process, wait for the child to exit*/
		wait(NULL);
	}
	}

	return (0);
}
