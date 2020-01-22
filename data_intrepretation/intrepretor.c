#include <stdio.h>
#include "../data_gathering_abstraction/flags.c"
#include "../libft/libft.h"
#include "intrepretor.h"

t_result *result_init(void)
{
    t_result *result;

    if (!malloc(sizeof(t_result)))
        return (NULL);
    result->spaces = 0;
    result->max_characters = -1;
    result->zeros = 0;
    result->minus = 0;
    return (result);
}

void zeros_calculator(t_format *holder, t_result *result, int size)
{
    if (holder->precision > size && holder->precision)
        result->zeros = holder->precision - size;
    else if (!holder->precision && holder->zero)
    {
        if (holder->field_width > size)
            result->zeros = holder->field_width;
    }
}

void spaces_calculator(t_format *holder, t_result *result, int size)
{
    if (holder->minus)
        result->minus = 1;
    if (holder->field_width > size && holder->field_width)
    {
        if (!holder->precision)
            result->spaces = holder->field_width - size;
        else if (holder->precision && holder->precision > size)
            result->spaces = holder->field_width - holder->precision;
    }
}
/*
** the d specifier
*/

int intrepert(char *fstr, va_list alist, int number)
{
    t_format *holder;
    t_result *result;
    char *str;

    str = ft_itoa(number);
    holder = get_data(fstr, alist);
    result = result_init();
    zeros_calculator(holder, result, ft_strlen(str));
    printf("0 : %d\nspaces: %d\nmc:  %d", result->zeros, result->spaces, result->max_characters);
    return (0);
}
void ft_printf(char *str, ...)
{
    va_list ab;
    va_start(ab, str);
    intrepert(str, ab, 1234);
    va_end(ab);
}

int main()
{
    //ft_printf("%0100");
    printf("%7.2d", 1234);
    return (0);
}
