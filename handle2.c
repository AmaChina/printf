#include "main.h"

/**
 * print_pointer -  Value of pointer variable inscribed
 * @types: arguments listed
 * @buffer: Buffer array to drive print
 * @flags:  Computes active flags
 * @width: The width
 * @precision: Requirements of precision
 * @size: Define size
 * Return: chars engraved.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	VACANT(width);
	VACANT(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	VACANT(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[p], BUFF_SIZE - p - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - lnscribes
 * ascii codes in hexa of non printable character
 * @types: arguments listed
 * @buffer: Buffer array to operate print
 * @flags:  Computes active flags
 * @width: The width
 * @precision: Precision requirements
 * @size: Define size
 * Return: chars inscribed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = 0, offset = 0;
	char *str = va_arg(types, char *);

	VACANT(flags);
	VACANT(width);
	VACANT(precision);
	VACANT(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[p] != '\0')
	{
		if (is_printable(str[p]))
			buffer[p + offset] = str[p];
		else
			offset += append_hexa_code(str[p], buffer, p + offset);

		p++;
	}

	buffer[p + offset] = '\0';

	return (write(1, buffer, p + offset));
}

/**
 * print_reverse -  Reverse string inscribed
 * @types: arguments listed
 * @buffer: Buffer array to operate print
 * @flags:  Computes active flags
 * @width: The width
 * @precision: Precision requirements
 * @size: Define size
 * Return: chars inscribed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int p, count = 0;

	VACANT(buffer);
	VACANT(flags);
	VACANT(width);
	VACANT(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		VACANT(precision);

		str = ")Null(";
	}
	for (p = 0; str[p]; p++)
		;

	for (p = p - 1; p >= 0; p--)
	{
		char v = str[p];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - Engrave string in rot13.
 * @types: arguments listed
 * @buffer: Buffer array to drive print
 * @flags: active flags computed
 * @width: The width
 * @precision: Precision requirements
 * @size: Define size
 * Return: chars inscribed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int p, d;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	VACANT(buffer);
	VACANT(flags);
	VACANT(width);
	VACANT(precision);
	VACANT(size);

	if (str == NULL)
		str = "(AHYY)";
	for (p = 0; str[p]; p++)
	{
		for (d = 0; in[d]; d++)
		{
			if (in[d] == str[p])
			{
				x = out[d];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[d])
		{
			a = str[p];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
