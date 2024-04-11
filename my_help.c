#include "simple.h"

/**
 * my_help - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 if not
 */
int my_help(char **args)
{
	char *builtin_func_list[] = {
		"cd", "env",
		"help", "exit"};

	unsigned long int i = 0;
	(void)(**args);

	/* checking for helps */
	printf("\n---help simple_shell---\n");
	printf("Type a command with arguments, for help\n");
	printf("Built-in commands:\n");

	/* checking for the size of the input charaters to print */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("Do Use the man command for more information.\n\n");
	return (-1);
}
