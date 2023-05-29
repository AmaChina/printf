#include "main.h"
/**
 * handle_write_char - print string
 * @k: type of char
 * @buffer: array of buffer for print
 * @flags:  checks active flags
 * @width: width
 * @precision: specify precision
 * @size: specify size
 * Return: printed characters number
 */
int handle_write_char(char k, char buffer[],
int flags, int width, int precision, int size)
{
	int n = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[n++] = k;
	buffer[n] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (n = 0; n < width - 1; n++)
			buffer[BUFF_SIZE - n - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - n - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - n - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - print string
 * @is_negative: list arguments
 * @ind: type of character
 * @buffer: array of buffer
 * @flags: computes active flags
 * @width: obtains width
 * @precision: specify precision
 * @size: specify size
 * Return: number of characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, pad, extra_ch));
}

/**
 * write_num - writes number
 * @ind: where number starts on buffer
 * @buffer: Buffer
 * @flags: obtains active flags
 * @width: obtains width
 * @prec: specify precision
 * @length: length of number
 * @pad: char of padding
 * @extra_c: extra character
 * Return: number of printed characters
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char pad, char extra_c)
{
	int n, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (n = 1; n < width - length + 1; n++)
			buffer[n] = pad;
		buffer[n] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], n - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], n - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], n - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - prints unsigned integer
 * @is_negative: indicates if num is neg
 * @ind: where number starts in the buffer
 * @buffer: array of characters
 * @flags: specify active flags
 * @width: specify width
 * @precision: specify precision
 * @size: specify size
 * Return: number of printed numbers
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, n = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pad = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > length)
	{
		for (n = 0; n < width - length; n++)
			buffer[n] = pad;

		buffer[n] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], n));
		}
		else
		{
			return (write(1, &buffer[0], n) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - print mem address
 * @buffer: array of characters
 * @ind: where the number starts in the buffer
 * @length: specify number length
 * @width: specify width
 * @flags: specify active flags
 * @pad: padding character
 * @extra_c: extra characters
 * @pad_start: where padding starts
 * Return: number of printed characters
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char extra_c, int pad_start)
{
	int n;

	if (width > length)
	{
		for (n = 3; n < width - length + 3; n++)
			buffer[n] = pad;
		buffer[n] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], n - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], n - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], n - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
