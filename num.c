#include <stdio.h>

/**
 ** main - Entry point
 ** Return: Always 0 (Success)
 **/
int main()
{
	int i;
	/because of the numbers 0 - 9 are found between 48 & 58/
		for (i = 48; i < 58; i++)
		{
			putchar(i);
		}
	putchar('\n');

	return 0;
}

