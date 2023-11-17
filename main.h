#ifndef _PRINTF_H
#define _PRINTF_H

/*
 * File: main.h
 * auth: me
 * Time: Now
 * used in this directory
 */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct
 * @unsign: flag
 * @plus_flag: on if +
 * @space_flag: on if #
 * @hashtag_flag: on if _flag
 * @zero_flag: on if 0
 * @minus_flag: on if -
 * @width: width
 * @precision: precision
 * @h_modifier: h_modifier
 * @l_modifier: l_modifier
 */

typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - dtruct
 * @specifier: format token
 * @f: function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/*_put.c module */
int _puts(char *str);
int _putchar(int c);

/*functions*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/*number.c module*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/*convert_number.c*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/*simple_printers*/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);


/*numbers*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/*params module*/
void init_params(params_t *params, va_list ap);

/* string_fields.c module */
char *get_precision(char *p, params_t *params, va_list ap);

/*specifier.c*/
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/*string_fields.c*/
char *get_precision(char *p, params_t *params, va_list ap);

/*_printf */
int _printf(const char *format, ...);
#endif
