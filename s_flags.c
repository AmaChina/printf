#include "main.h"
/**
 * get_flags - gets active flags
 * @format: string format for arguments
 * @n: gets parameters
 * Return: return flags
 */
int get_flags(const char *format, int *n)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_n;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_n = *n + 1; format[curr_n] != '\0'; curr_n++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_n] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*n = curr_n - 1;

	return (flags);
}
