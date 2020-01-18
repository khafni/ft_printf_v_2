#include "../libft/libft.h"
#include <stdio.h>
#include "../data_gathering_abstraction/flags.c"



void print_string (char *fstr, va_list alist)
{
    t_format *holder;
    int l;

    l = ft_strlen(fstr);
    holder = get_data(fstr, alist);

    if (!holder->precision)
    {
        if (l > holder->field_width)
            ft_putstr_fd(fstr, 1);
    }
}

void ft_printf(char *str, ...)
{
    va_list ab;
    va_start(ab, str);
    print_char(str, ab);
   
}

int main()
{
    printf("%---5s", "brw");
    return (0);
}