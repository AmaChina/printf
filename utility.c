#include "main.h"
/**
 * is_printable - Gauges if char is presumable
 * @k: Character gauged
 * Return: 1 if k is presume, 0 otherwise
 */
int is_printable(char k)
{
	if (k >= 32 && k < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Attach ascci in hexadecimal code to buffer
 * @buffer: chars array
 * @n: Hint at which to begin adjoining.
 * @ascii_code: assci code.
 * Return: Constantly 3
 */
int append_hexa_code(char ascii_code, char buffer[], int n)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[n++] = '\\';
	buffer[n++] = 'x';

	buffer[n++] = map_to[ascii_code / 16];
	buffer[n] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Confirm char is a digit
 * @k: The char to be gauge
 * Return: 1 if f is a digit, 0 otherwise
 */
int is_digit(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Emits a number to the defined size
 * @num: Number to be emitted
 * @size: Number showing type emit
 * Return: Evacuated value num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Eject a number to defined size
 * @num: Number to eject
 * @size: Number showing the type to excude
 * Return: Discharged value num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
