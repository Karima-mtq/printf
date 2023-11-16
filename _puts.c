#include "main.h"

/**
 * _puts - prints string\n
 * @str: string
 * Return: void
 */
int _puts(char *str)
{
	char *s = str;

	while (*str)
		_putchar(*str++);
	return (str - s);

}
/**
 * _putchar - writes
 * @c: charachter
 * Return: 1 or 0
 */
int _putchar(int c)
{
	static int j;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
