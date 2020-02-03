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
void p_spaces(t_result *result)
{
    int i;

    i = 0;
    while (i < result->spaces)
    {
        ft_putchar_fd(' ', 1);
        i++;
    }
}

void p_zeros(t_result *result)
{
    int i;

    i = 0;
    while (i < result->zeros)
    {
        ft_putchar_fd('0', 1);
        i++;
    }
}

void    p_num(t_result *result)
{
    int n;

    n = -1 * ft_atoi(result->value);
    /*
    if (!ft_atoi(result->value) && !result->data->precision)
    {
        return ;
    }
    */
    if (!ft_atoi(result->value))
        return ;
    else
    {
        if (result->neg)
        {
            ft_putnbr_fd(n, 1);
        }
        else
        {
            ft_putstr_fd(result->value, 1);
        }
    }
}

void print_result(t_result *result)
{
    if (result->neg && result->minus)
    {
        ft_putchar_fd('-', 1);
        p_zeros(result);
        p_num(result);
        p_spaces(result);
    }
    else if (result->neg && !result->minus)
    {
        p_spaces(result);
        ft_putchar_fd('-', 1);
        p_zeros(result);
        p_num(result);
    }
    else if (!result->neg && result->minus)
    {
        p_zeros(result);
        p_num(result);
        p_spaces(result);
    }
    else
    {
        p_spaces(result);
        p_zeros(result);
        p_num(result);
    }
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
    result_destroy(result);
}
int ft_printf(char *str, ...)
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
            ft_putchar_fd(*str, 1);
        }
        str++;
    }
    va_end(alist);
    return (0);
}
/*
int main()
{    
    ft_printf("%10.9de\n", -4);
    ft_printf("%10.9de", -4);
    return (0);
}*/