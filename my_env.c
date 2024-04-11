#include "simple.h"

/**
 * my_env - functions that prints
 * enviroment variables
 * @args: arguments for the variables
 *
 * Return: 1 on success, 0 if not
 */

int my_env(char **args)
{
	int e = 0;

	(void)(**args);

	/* checking the enveronment */

	while (environ[e])
	{
		write(STDOUT_FILENO, environ[e], strlen(environ[e]));
		write(STDOUT_FILENO, "\n", 1);
		e++;
	}
	return (-1);
}
