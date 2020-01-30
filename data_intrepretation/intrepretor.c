#include <stdio.h>
#include "../libft/libft.h"
#include "../data_gathering_abstraction/data_gathering.h"
#include "intrepretor.h"

t_result *result_init(void)
{
    t_result *result;

    if (!(result = malloc(sizeof(t_result))))
        return (NULL);
    result->spaces = 0;
    result->max_characters = -1;
    result->zeros = 0;
    result->minus = 0;
    result->neg = 0;
    result->value = NULL;
    return (result);
}

void    result_destroy(t_result *result)
{
    free(result->value);
    free(result->data->value);
    free(result->data);
    free(result);
}

void zeros_calculator(t_format *holder, t_result *result, int size)
{
    if (result->neg)
        size--;
    if ((holder->flags_existence & PRECISION) && !holder->precision)
        return ;
    if (holder->precision > size && holder->precision)
        result->zeros = holder->precision - size;
    //else if (!holder->precision && holder->zero)
    else if (holder->zero)
    {
        if (holder->field_width > size)
            result->zeros = holder->field_width - size;
    }
}

void spaces_calculator(t_format *holder, t_result *result, int size)
{
    int pr_extra;

    if (!ft_atoi(result->value) && result->data->precision >= 0)
        size--;
    pr_extra = holder->precision + 1;
    pr_extra = (!result->neg) ? holder->precision : pr_extra;
    if (holder->field_width > size && holder->field_width && !holder->zero)
    {
        //if (!holder->precision && !holder->zero)
        if (!holder->precision && (holder->flags_existence & PRECISION))
            result->spaces = holder->field_width - size;
        else if (holder->precision && holder->precision > size)
            result->spaces = holder->field_width - pr_extra;
        else if (holder->precision && holder->precision <= size)
            result->spaces = holder->field_width - size;
    }
}
t_result *intrepert(char *fstr, va_list alist)
{
    t_format *holder;
    t_result *result;

    holder = get_data(fstr, alist);
    result = result_init();
    result->data = holder;
    if (holder->minus)
        result->minus = 1;
    if (ft_atoi(holder->value) < 0)
        result->neg = 1;
    if (holder->field_width < 0)
    {
        holder->field_width *= -1;
        result->minus = 1;
    }
    result->value = ft_strdup(holder->value);
    spaces_calculator(holder, result, ft_strlen(result->value));
    zeros_calculator(holder, result, ft_strlen(result->value));
    return (result);
}

/*void bobo(char *str, ...)
{
    va_list alist;
    t_result *r;
    
    va_start(alist, str);
    r = intrepert(str, alist);
    va_end(alist);
}*/
void r_debugger(char *str, ...)
{
	va_list alist;
	t_result *holder;

	va_start(alist, str);
	holder = intrepert(str, alist);
	ft_putnbr_fd(holder->spaces, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->max_characters ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->zeros ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->minus ,1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(holder->neg ,1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd(holder->value, 1);
	va_end(alist);
}
/*
int main()
{
    r_debugger("%14.7d");
    return (0);
}*/