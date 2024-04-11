#include "simple.h"

/**
 * get_stream - reading a line from the streams
 * Return: pointer that points the the read line
 */
char *get_stream(void)
{
	int buffersize = 1024;
	int i = 0;
	char *readl = malloc(sizeof(char) * buffersize);
	int character;

	if (readl == NULL)
	{
		fprintf(stderr, "allocation error in get_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(readl);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			readl[i] = '\0';
			return (readl);
		}
		else
		{
			readl[i] = character;
		}
		i++;
		if (i >= buffersize)
		{
			buffersize += buffersize;
			readl = realloc(readl, buffersize);
			if (readl == NULL)
			{
				free(readl);
				fprintf(stderr, "reallocation error in get_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
