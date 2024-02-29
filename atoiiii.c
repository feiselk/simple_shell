#include "shell.h"

/**
 * inter - returns true if shell is interactive mode
 * @infoo: struct address
 *
 * Return: 1 if inter mode, 0 otherwise
 */
int inter(info_t *infoo)
{
	return (isatty(STDIN_FILENO) && infoo->readfd <= 2);
}

/**
 * delimm - checks if character is a delimeter
 * @c: the char to check
 * @deli: the delimeter string
 * Return: 1 if true, 0 if false
 */
int delimm(char c, char *deli)
{
	while (*deli)
		if (*deli++ == c)
			return (1);
	return (0);
}

/**
 *alpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * zatoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int zatoi(char *s)
{
	int i, sigma = 1, flagg = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flagg != 2; i++)
	{
		if (s[i] == '-')
			sigma *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flagg = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flagg == 1)
			flagg = 2;
	}

	if (sigma == -1)
		output = -result;
	else
		output = result;

	return (output);
}
