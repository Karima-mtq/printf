#include "main.h"
/**
 * convert - function
 * @num: number
 * @base: base
 * @flags: arg flags
 * @params: param struct
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - function
 * @ap: arg
 * @params: struct
 * Return: int
 */

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long i;

	if (params->l_modifier)
		i = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		i = (unsigned short int)va_arg(ap, unsigned int);
	else
		i = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(i, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @ap: arg pointer
 * @params: struct
 * Return: int
 */

int print_address(va_list ap, params_t *params)
{
	unsigned long int i = va_arg(ap, unsigned long int);
	char *s;

	if (!i)
		return (_puts("(nil)"));

	s = convert(i, 16, CONVERT_UNSIGNED || CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
