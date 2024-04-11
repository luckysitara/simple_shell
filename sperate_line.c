#include "simple.h"

/**
 * sptlf - splitng a string into multiple strings
 * @readl: those string to be splited
 *
 * Return: pointer that points to the new array
 */

char **sptlf(char *readl)
{
	int buffersize = 64;
	int i = 0;
	char **tokens = malloc(buffersize * sizeof(char *));
	char *token;

	/* runing a loop that check for token */
	if (!tokens)
	{
		fprintf(stderr, "allocation of an error in the split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(readl, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			/* stoping the loop with break */
			break;
		}
		tokens[i] = token;
		i++;

		/* cheaking the size of the buffersize */
		if (i >= buffersize)
		{
			buffersize += buffersize;
			tokens = realloc(tokens, buffersize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation of an error in the split_line: tokens");

				/* Free the old buffer before exiting on realloc failure */
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
