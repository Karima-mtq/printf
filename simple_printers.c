#include "main.h"
/**
 * print_from_to - prints
 * @start: beginning
 * @stop: end
 * @except: except address
 * Return: int
 */
int print_from_to(char *start, char *stop, char *except)
{
	int somme = 0;

	while (start <= stop)
	{
		if (start != except)
			somme += _putchar(*start);
		start++;
	}
	return (somme);
}
/**
 * print_rev - prints
 * @ap: string
 * @params: struct
 * Return: int
 */
int print_rev(va_list ap, params_t *params)
{
	int l, somme = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (l = 0; *str; str++)
			l++;
		str--;
		for (; l > 0; l--, str--)
			somme += _putchar(*str);
	}
	return (somme);
}
/**
 * print_rot13 - prints in rot13
 * @ap: string
 * @params: struct
 * Return: int
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, indice;
	int conteur = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	indice = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
			|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			indice = a[i] - 65;
			conteur += _putchar(arr[indice]);
		}
		else
			conteur += _putchar(a[i]);
		i++;
	}
	return (conteur);
}
