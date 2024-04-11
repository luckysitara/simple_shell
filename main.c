#include "simple.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main(void)
{
	/* determining if the file descriptor is associated with any terminal */
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	/*checking if it is interactive or not */

	else
	{
		non_interactive();
	}
	return (0);
}
