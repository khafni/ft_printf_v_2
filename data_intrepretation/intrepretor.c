#include <stdio.h>
#include "../libft/libft.h"
#include "../data_gathering_abstraction/data_gathering.h"
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
    result->left = 0;
    result->d_value = 0;
    result->s_value = NULL;
    return (result);
}

void zeros_calculator(t_format *holder, t_result *result, int size)
{
    if (holder->precision > size && holder->precision)
        result->zeros = holder->precision - size;
    else if (!holder->precision && holder->zero)
    {
        if (holder->field_width > size)
            result->zeros = holder->field_width - size;
    }
}

void spaces_calculator(t_format *holder, t_result *result, int size)
{
    if (holder->minus)
        result->minus = 1;
    if (holder->field_width > size && holder->field_width)
    {
        if (!holder->precision && !holder->zero)
            result->spaces = holder->field_width - size;
        else if (holder->precision && holder->precision > size)
            result->spaces = holder->field_width - holder->precision;
        else if (holder->precision && holder->precision <= size)
            result->spaces = holder->field_width - size;
    }
}
t_result *intrepert(char *fstr, va_list alist)
{
    t_format *holder;
    t_result *result;
    char *str;

    if (number < 0)
        result->minus = 1;
    str = ft_itoa(number);
    holder = get_data(fstr, alist);
    result = result_init();
    spaces_calculator(holder, result, ft_strlen(str));
    zeros_calculator(holder, result, ft_strlen(str));
    if (holder->minus)
        result->left = 1;
    return (result);
}