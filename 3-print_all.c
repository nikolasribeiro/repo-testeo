#include "variadic_functions.h"
/**
* print_char - print char
* @str: string pointer
* @valist: takes in a list
*/
void print_char(char *str, va_list valist)
{
	printf("%s%c", str, va_arg(valist, int));
}

/**
* print_int - print int
* @str: string pointer
* @valist: takes in a list
*/
void print_int(char *str, va_list valist)
{
	printf("%s%d", str, va_arg(valist, int));
}

/**
* print_float - print float
* @str: string pointer
* @valist: takes in a list
*/
void print_float(char *str, va_list valist)
{
	printf("%s%f", str, va_arg(valist, double));
}

/**
* print_string - print a string
* @str: string pointer
* @valist: takes in a list
*/
void print_string(char *str, va_list valist)
{
	char *temp;

	temp = va_arg(valist, char *);
	if (temp == NULL)
	{
		temp = "(nil)";
	}
	printf("%s%s", str, temp);
}

/**
* print_all - prints everything
* @format: takes in a format
*/
void print_all(const char * const format, ...)
{
	va_list valist;
	int i = 0, j;
	char *str;

	options select_option[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(valist, format);
	str = "";
	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (select_option[j].c[0] == format[i])
			{
				select_option[j].call_fun(str, valist);
				str = ", ";
				break;
			}
			j++;
		}
	i++;
	}
	printf("\n");
	va_end(valist);
}
