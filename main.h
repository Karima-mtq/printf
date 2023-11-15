#ifndef _PRINTF_H
#define _PRINTF_H

/*
 * File: main.h
 * auth: me
 * Time: Now
 * 	used in this directory
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
 * @h_modifer: h_modifier
 * @l_modifier: l_modifier
 */

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag :1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier :1;
	unsigned int l_modifier :1;
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

/*_put module */
int _puts(char *str);
int _putchar(int c);
/*functions*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

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

/*_printf */
int _printf(const char *format, ...);
#endif
