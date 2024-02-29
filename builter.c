#include "shell.h"

/**
 * zexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int zexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _errayoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errayoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int cd(info_t *info)
{
	char *a, *dier, buffer[1024];
	int chdir_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dier = _setenv(info, "HOME=");
		if (!dier)
			chdir_ret = /* TODO: what should this be? */
				chdir((dier = _setenv(info, "PWD=")) ? dier : "/");
		else
			chdir_ret = chdir(dier);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_setenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_setenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dier = _setenv(info, "OLDPWD=")) ? dier : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _setenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int help(info_t *info)
{
	char **arg_arya;

	arg_arya = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arya); /* temp att_unused workaround */
	return (0);
}

