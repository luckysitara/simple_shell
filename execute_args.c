#include "simple.h"

/**
 * get_execute - run if command is a builtin or a process
 * state
 *
 * @args: commands arguments or flag
 *
 * Return: 1 on sucess, 0 if not
 */
int get_execute(char **args)
{
	char *builtin_func_list[] = {"cd", "env", "help", "exit"};

	int (*builtin_func[])(char **) = {
		&my_cd,
		&my_env,
		&my_help,
		&myget_exit};

	unsigned long int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	/* checking for builtin commands */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
	/* if it is a builtin command execute it */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/* make a npid */
	return (npid(args));
}
