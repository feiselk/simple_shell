#include "shell.h"

/**
 * history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unsettingalias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unsettingalias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * settingalias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int settingalias(info_t *info, char *str)
{
	char *c;

	c = _strchr(str, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (unsettingalias(info, str));

	unsettingalias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * aliass - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int aliass(list_t *node)
{
	char *c = NULL, *b = NULL;

	if (node)
	{
		c = _strchr(node->str, '=');
		for (b = node->str; b <= c; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int alias(info_t *info)
{
	int i = 0;
	char *c = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_list(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		c = _strchr(info->argv[i], '=');
		if (c)
			settingalias(info, info->argv[i]);
		else
			print_list(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
