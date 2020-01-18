#include "../libft/libft.h"
#include <stdio.h>
#include "../data_gathering_abstraction/flags.c"

void string_cut(char *string, int length, int precision)
{
    int i;

    i = 0;
    if (precision < length)
    {
        while (i != precision)
            i++;
        string[i] = '\0';
    }
}

void	ft_putstr_pre(char *s,int pre)
{
	if (s == NULL)
		return ;
    if (!pre)
    {
        ft_putstr_fd(s, 1);
        return ;
    }
    else 
    {
        while (*s && pre)
        {
            ft_putchar_fd(*s, 1);
            s++;
            pre--;
        }
    }
}

void print_n_space(int fw, int size)
{
    if (fw > size)
    {
        fw -= size;
        while (fw)
        {
            ft_putchar_fd(' ', 1);
            fw--;
        }
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

void print_string(char *fstr, va_list alist)
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
        print_n_space(holder->field_width - 1, l);
        ft_putstr_pre(va_arg(alist, char *), holder->precision);
    }
    else
    {
        ft_putstr_pre(va_arg(alist, char *), holder->precision);
        print_n_space(holder->field_width, l);
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
    ft_printf("%6s", "abcdefg");
    return (0);
}