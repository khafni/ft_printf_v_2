#include "../libft/libft.h"
#include <stdio.h>
#include "../data_gathering_abstraction/flags.c"



void print_n_space(int n, int size)
{
    while (n && size < )
    {
        ft_putchar_fd(' ', 1);
        n--;
    }
}

int ft_strnlen(char *str, int n)
{
    int i;

	i = 0;
	while (str[i] && i < n)
	{
		i++;
	}
	return (i);
}

void print_string (char *fstr, va_list alist)
{
    t_format *holder;
    int ls;
    int l;
    int fw;

    holder = get_data(fstr, alist);
    fw = holder->field_width;
    ls = ft_strnlen(fstr, holder->precision);
    l = ft_strlen(fstr);
    if (!holder->minus)
        {
            print_n_space(holder->field_width - 1, );
            ft_putstr_fd(va_arg(alist, char *), 1);
        }
    
}

void ft_printf(char *str, ...)
{
    va_list ab;
    va_start(ab, str);
    print_string(str, ab);
    va_end(ab);
   
}

int main()
{
    ft_printf("%20s", "momo");
    return (0);
}