#include "main.h"

/**
 * print_char - function
 * @ap: arg
 * @params: struct
 * Return: int
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, somme = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		somme += _putchar(ch);
	while (pad++ < params->width)
		somme += _putchar(pad_char);
	if (!params->minus_flag)
		somme += _putchar(ch);
	return (somme);
}

/**
 * print_int - funct
 * @ap: argument pointer
 * @params: param
 * Return: int
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}
/**
 * print_string - prints string
 * @ap: arg pointer
 * @params: param
 * Return: int
 */

int print_string(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, somme = 0, i = 0, j;

	(void)params;

	switch ((int)(!s))
	case 1:
		s = NULL_STRING;

	j = pad = _strlen(s);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				somme += _putchar(*s++);
		else
			somme += _puts(s);
	}
	while (j++ < params->width)
		somme += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				somme += _putchar(*s++);
		else
			somme += _puts(s);
	}
	return (somme);
}
/**
 * print_percent - function
 * @ap: arg
 * @params: struct
 * Return: int
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - funct
 * @ap: arg
 * @params: param
 * Return: int
 */
int print_S(va_list ap, params_t *params)
{
	char *s = va_arg(ap, char *);
	char *hex;
	int somme = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			somme += _putchar('\\');
			somme += _putchar('x');
			hex = convert(*s, 16, 0, params);
			if (!hex[1])
				somme += _putchar('0');
			somme += _puts(hex);
		}
		else
		{
			somme += _putchar(*s);
		}
	}
	return (somme);
}
