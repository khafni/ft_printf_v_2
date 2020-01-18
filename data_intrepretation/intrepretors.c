#include <stdio.h>
#include "../data_gathering_abstraction/flags.c"
#include "../libft/libft.h"

void print_n_space(int n)
{
    while (n--)
    {
        ft_putchar_fd(' ', 1);
    }
}
int print_char(char *fstr, va_list alist)
{
    t_format *holder;

    holder = get_data(fstr, alist);
    if (holder->field_width > 0)
    {
        if (holder->minus > 0)
        {
            ft_putchar_fd(va_arg(alist, int), 1);
            print_n_space(holder->field_width - 1);
        }
        else
        {
            print_n_space(holder->field_width - 1);
            ft_putchar_fd(va_arg(alist, int), 1);
        }
    }
    else
    {
        ft_putchar_fd(va_arg(alist, int), 1);
    }
    return (0);
}