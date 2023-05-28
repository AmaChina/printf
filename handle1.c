#include "main.h"
/**
 * print_unsigned - produce unsigneed integer
 * @types: types
 * @buffer: buffer aaray
 * @flags: specify active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of printed characters
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 10) + '0';
		num /= 10;
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}


/**
 * print_octal -print unsigned integer in octal
 * @types: argument types
 * @buffer: buffer array
 * @flags:  specify active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of printed characters
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[n--] = '0';

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - print unsigned integer in hexadecimal
 * @types: lists arguments
 * @buffer: buffer array
 * @flags:  specify active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of printed characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - print unsigned integer in upper hexadecimal
 * @types: list arguments
 * @buffer: buffer array
 * @flags:  specify active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of printed characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - print hexadecimal integer in lower or upper
 * @types: list argument
 * @map_to: array of values to be mapped
 * @buffer: array of buffer
 * @flags:  specify active flags
 * @flag_ch: computes active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: printed character
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[n--] = flag_ch;
		buffer[n--] = '0';
	}

	n++;

	return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}
