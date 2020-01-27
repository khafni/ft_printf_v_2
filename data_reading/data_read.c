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
void print_result(t_result *result)
{
    int i;

    i = 0;
    while (i < result->spaces)
    {
        ft_putchar_fd(' ', 1);
        i++;
    }
    while (i < result->zeros)
    {
        ft_putchar_fd('0', 1);
        i++;
    }
    i = 0;
    ft_putstr_fd(result->value, 1);
}
void g_parser(va_list alist, char **str_ptr)
{
    int l;
    char *pt;
    t_result *result;

    pt = extractor(*str_ptr);
    result = intrepert(*str_ptr, alist);
    print_result(result);
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
    printf("%6.7d\n", 4);
    ft_printf("%6.7d", 4);
    return (0);
}