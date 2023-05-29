#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_SPACE 16
#define F_HASH 8
#define F_ZERO 4
#define F_PLUS 2
#define F_MINUS 1

/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/**
 * struct form - struct operation
 * @form: format
 * @fx: related function
 */
struct form
{
	char form;
	int (*fx)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct form form_x - struct operation
 * @form: format
 * @form_x: The related function
 */
typedef struct form form_x;

int _printf(const char *format, ...);
int handle_print(const char *form, int *n,
va_list list, char buffer[], int size, int width, int precision, int flags);

/* Char and str functions */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print num functions */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Non Print char functions */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Mem Address functions */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns for other specs */
int get_flags(const char *format, int *n);
int get_width(const char *format, int *n, va_list list);
int get_precision(const char *format, int *n, va_list list);
int get_size(const char *format, int *n);

/* Reverse string functions */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Rot 13 functions */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width */
int handle_write_char(char k, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char pad, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pad, char extra_c, int pad_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
