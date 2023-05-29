#include "main.h"

/**
 * print_char -  char inscribed
 * @types: a of arguments listed
 * @buffer: Buffer array to operate print
 * @flags:  active flags computed
 * @width: The width
 * @precision: Precision requirements
 * @size: Define size
 * Return:  chars engraved
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char f = va_arg(types, int);

	return (handle_write_char(f, buffer, flags, width, precision, size));
}

/**
 * print_string - imprint string
 * @types:  a of arguments listed
 * @buffer: Buffer array to operate print
 * @flags: active flags computed
 * @width: Get width.
 * @precision: Requirements of precision
 * @size: Define size
 * Return: chars inscribed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, p;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (p = width - length; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (p = width - length; p > 0; p--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Engrave percent sign
 * @types: arguments listed
 * @buffer: Buffer array to control print
 * @flags:  computes active flags
 * @width: Get Width.
 * @precision: Precision requirements
 * @size: Define size
 * Return:  chars imprinted
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - lnscribes int
 * @types:  arguments listed
 * @buffer: Buffer array to drive print
 * @flags: active flags computed
 * @width: Get Width.
 * @precision: Requirements of precision
 * @size: Define size
 * Return:  chars engraved
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int n = BUFF_SIZE - 2;
	int is_negative = 0;
	long int h = va_arg(types, long int);
	unsigned long int num;

	h = convert_size_number(h, size);

	if (h == 0)
		buffer[n--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (h < 0)
	{
		num = (unsigned long int)((-1) * h);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[n--] = (num % 10) + '0';
		num /= 10;
	}

	n++;

	return (write_number(is_negative, n, buffer, flags, width, precision, size));
}

/**
 * print_binary -  unsigned number imprinted
 * @types: arguments listed
 * @buffer: Buffer array to drive print
 * @flags:  Computes active flags
 * @width: Get Width.
 * @precision: Precision requirements
 * @size: Define size
 * Return: chars imprinted
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int h, q, p, sum;
	unsigned int w[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	h = va_arg(types, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	w[0] = h / q;
	for (p = 1; p < 32; p++)
	{
		q /= 2;
		w[p] = (h / q) % 2;
	}
	for (p = 0, sum = 0, count = 0; p < 32; p++)
	{
		sum += w[p];
		if (sum || p == 31)
		{
			char b = '0' + w[p];

			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
