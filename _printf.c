#include "main.h"

/**
 * _printf - function
 * @format: string
 * Return: int 
 **/

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%' && *(ptr + 1) != '\0')
        {
            switch (*(ptr + 1))
            {
            case 'c':
                count += write(1, va_arg(args, int), 1);
                ptr++;
                break;
            case 's':
                count += write(1, va_arg(args, char *), 1);
                ptr++;
                break;
            case '%':
                count += write(1, "%", 1);
                ptr++;
                break;
            default:
                count += write(1, "%", 1);
                break;
            }
        }
        else
        {
            count += write(1, ptr, 1);
        }
    }

    va_end(args);

    return count;
}
