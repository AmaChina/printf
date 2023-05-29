#include "main.h"
/**
 * get_size - compute size
 * @format: format string
 * @n: takes input
 * Return: size
 */
int get_size(const char *format, int *n)
{
	int new_n = *n + 1;
	int size = 0;

	if (format[new_n] == 'l')
		size = S_LONG;
	else if (format[new_n] == 'h')
		size = S_SHORT;

	if (size == 0)
		*n = new_n - 1;
	else
		*n = new_n;

	return (size);
}
