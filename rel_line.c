#include "simple.h"

/**
 * readlf - reading a line from stdin
 *
 * Return: pointer that points to a str with the line content
 */
char *readlf(void)
{
	char *readl = NULL;
	size_t buffersize = 0;

	/* checking for end of file and exiting if found else free memory space*/
	if (getline(&readl, &buffersize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(readl);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* Free the old buffer before exiting on realloc failure */
			free(readl);
			perror("error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (readl);
}
