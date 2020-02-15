#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
#include "data_read.h"
#include "../utills/utills.h"

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
  long n;

  n = -1 * ft_atoi(result->value);
  if (n == MIN_INTEGER)
  {
    n = 2147483648;
  }
  if (!ft_atoi(result->value) && (result->data->flags_existence & PRECISION))
    return ;
   else
     {
       if (result->neg && (ft_atoi(result->value) != MIN_INTEGER))
	        ft_putnbr_fd(n, 1);
        else if (ft_atoi(result->value) == MIN_INTEGER)
            ft_putnbr_long(2147483648);
	    else
	        ft_putstr_fd(result->value, 1);
     }
  (void)n;
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
int g_parser(va_list alist, char **str_ptr)
{
    int l;
    int len_r;
    char *pt;
    t_result *result;

    len_r = 0;
    pt = extractor(*str_ptr);
    result = intrepert(*str_ptr, alist);
    print_result(result);
    l = format_length(*str_ptr) + 1;
    len_r = result->spaces + result->zeros + ft_strlen(result->value);
    *str_ptr += l;
    free(pt);
    result_destroy(result);
    return (len_r);
}
int ft_printf(char *str, ...)
{
    va_list alist;
    int l;

    l = 0;
    va_start(alist, str);
    while (*str)
    {
        if (*str == '%')
        {
                l += g_parser(alist, &str);
        }
        else
        {
            ft_putchar_fd(*str, 1);
            l++;
        }
        str++;
    }
    va_end(alist);
    return (l);
}
/*
int main()
{    
    ft_printf("%10.9de\n", -4);
    ft_printf("%10.9de", -4);
    return (0);
}*/
