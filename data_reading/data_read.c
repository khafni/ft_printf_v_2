#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
#include "../libft/libft.h"

int format_length (char *s)
{
	int length;

	length = 0;
	s++;
	while (*s != 'c' && *s != 's' && *s != 'p' &&
	*s != 'd' && *s != 'i' && *s != 'u' &&
	*s != 'x' && *s != 'X' && *s != '%' && *s)
	{
		length++;
		s++;
	}
	return (length);
}

char *extractor(char *format)
{
	char *holder;
	int l;

	l = format_length(format);
	format++;
	holder = malloc(sizeof(char) * l);
	ft_strlcpy(holder, format, l + 1);
	return (holder);
}
void g_parser(va_list alist, char **str_ptr)
{
    int l;
    char *pt;

    pt = extractor(*str_ptr);
    printf("%s", pt);
    l = format_length(*str_ptr) + 1;
    *str_ptr += l;
    free(pt);
}
void ft_printf(char *str, ...)
{
    va_list alist;
    va_start(alist, str);
    while (*str)
    {
        if (*str == '%')
        {
                g_parser(alist, &str);
        }
        else
        {
            //ft_putchar_fd(*str, 1);
        }
        str++;
    }
    va_end(alist);
}

int main()
{
    ft_printf("%+-----!@#$####% %f233232d");
    return (0);
}