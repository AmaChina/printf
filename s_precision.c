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
	int new_n = *n + 1;
	int precision = -1;

	if (format[new_n] != '.')
		return (precision);

	precision = 0;

	for (new_n += 1; format[new_n] != '\0'; new_n++)
	{
		if (is_digit(format[new_n]))
		{
			precision *= 10;
			precision += format[new_n] - '0';
		}
		else if (format[new_n] == '*')
		{
			new_n++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = new_n - 1;
	return (precision);
}
