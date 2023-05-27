#include "main.h"
/**
 * handle_print - Prints argument according to type
 * @form: formatted strings
 * @list: list of arguments to print
 * @ind: ind
 * @buffer: array of buffer
 * @flags: active flags
 * @width: obtains width
 * @precision: specify precision
 * @size: specify size
 * Return: 1 or 2;
 */
int handle_print(const char *form, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int n, unknow_len = 0, printed_chars = -1;
	form_x form_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (n = 0; form_types[n].form != '\0'; n++)
		if (form[*ind] == form_types[n].form)
			return (form_types[n].fx(list, buffer, flags, width, precision, size));

	if (form_types[n].form == '\0')
	{
		if (form[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (form[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (form[*ind] != ' ' && form[*ind] != '%')
				--(*ind);
			if (form[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &form[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
