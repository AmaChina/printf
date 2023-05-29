#include "main.h"
/**
 * get_precision - Computes precision for printing
 * @format: Constructed string to inscribe arguments
 * @n: arguments to be inscribed
 * @list: arguments listed
 * Return: The precision.
 */
int get_precision(const char *format, int *n, va_list list)
{
	int curr_n = *n + 1;
	int precision = -1;

	if (format[curr_n] != '.')
		return (precision);

	precision = 0;

	for (curr_n += 1; format[curr_n] != '\0'; curr_n++)
	{
		if (is_digit(format[curr_n]))
		{
			precision *= 10;
			precision += format[curr_n] - '0';
		}
		else if (format[curr_n] == '*')
		{
			curr_n++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = curr_n - 1;

	return (precision);
}

#include "main.h"
/**
 * get_size - Computes size to cast  argument
 * @format: Constructed string to inscribe arguments
 * @n: arguments list to be inscribed
 * Return: precision
 */
int get_size(const char *format, int *n)
{
	int curr_n = *n + 1;
	int size = 0;

	if (format[curr_n] == 'l')
		size = S_LONG;
	else if (format[curr_n] == 'n')
		size = S_SHORT;

	if (size == 0)
		*n = curr_n - 1;
	else
		*n = curr_n;

	return (size);
}
