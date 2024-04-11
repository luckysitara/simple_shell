#include "simple.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{
	char *readl;
	char **sptl;
	int state = -1;

	do {
		/* print Cisfun prompt with $ sign */
		printf("Cisfun$ ");

		/* reading from standard input */
		readl = readlf();

		/* spliting line by using tokens */
		sptl = sptlf(readl);
		state = get_execute(sptl);

		/* avoiding leaking and free allocatted memory */
		free(readl);
		free(sptl);

		/* exiting state */
		if (state >= 0)
		{
			exit(state);
		}
	} while (state == -1);
}
