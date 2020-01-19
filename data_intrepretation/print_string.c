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

void print_n_space(int fw, int size, int precision)
{
    printf("%d %d\n", size, precision);
    if (size > precision)
        size = precision;
    if (fw > size)
    {
        fw -= size;
        printf("number of spaces to be printed : %d\n", fw);
        while (fw > 1)
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
    int size;
    int fw;

    holder = get_data(fstr, alist);
    fw = holder->field_width;
    ls = ft_strnlen(fstr, holder->precision);
    size = ft_strlen(fstr);
    if (!holder->minus)
    {
        print_n_space(fw + 1,  size, holder->precision);
        ft_putstr_pre(va_arg(alist, char *), holder->precision);
    }
    else
    {
        ft_putstr_pre(va_arg(alist, char *), holder->precision);
        print_n_space(fw + 1, size, holder->precision);
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
    ft_printf("%-6.1s", "abcd");
    return (0);
}