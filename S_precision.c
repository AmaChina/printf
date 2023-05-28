#include "main.h"

/**
 * get_precision - Computes precision for printing
 * @format: Constructed string to inscribe arguments
 * @i: arguments to be inscribed
 * @list: arguments listed
 *
 * Return: The precision.
 */
int get_precision(const char *format, int *p, va_list list)
{
	int curr_i = *p + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*p = curr_i - 1;

	return (precision);
}

vi get_size.c
#include "main.h"

/**
 * get_size - Computes size to cast  argument
 * @format: Constructed string to inscribe arguments
 * @i: arguments list to be inscribed.
 *
 * Return: The precision.
 */
int get_size(const char *format, int *p)
{
	int curr_i = *p + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'n')
		size = S_SHORT;

	if (size == 0)
		*p = curr_i - 1;
	else
		*p = curr_i;

	return (size);
}
