#include "simple.h"

/**
 * non_interactive - interpreter for unix or linux commands
 *
 * Return: void always
 */
void non_interactive(void)
{
	char *readl;
	char **sptl;
	int state = -1;

	do {
		/* reading from standard input */
		readl = get_stream();

		/* spliting line using tokens */
		sptl = sptlf(readl);
		state = get_execute(sptl);

		/* avoiding leaking memory and freeing  memory */
		free(readl);
		free(sptl);

		/* exiting  state */
		if (state >= 0)
		{
			exit(state);
		}
	} while (state == -1);
}
