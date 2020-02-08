
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

void zeros_calculator_normal (t_format *holder, t_result *result, int size)
{
    if (holder->precision > 0 && !(holder->flags_existence & FW_ZERO))
        result->zeros = holder->precision - size;
    if ((holder->precision > 0) && (holder->flags_existence & FW_ZERO)
    && holder->field_width > 0)
        result->zeros = holder->precision - size;
    else if (holder->precision < 0 && (holder->flags_existence & FW_ZERO)
    && holder->field_width > 0)
    {
        result->zeros = holder->field_width - size;
    }
}

void zeros_calculator_zero (t_format *holder, t_result *result)
{
    if (!(holder->flags_existence & FW_ZERO))
    {
        if (holder->precision < 0)
            result->zeros = 1;
        else if (holder->precision > 0)
            result->zeros = holder->precision;
    }
    else if (holder->flags_existence & FW_ZERO)
    {
        if (holder->precision < 0)
            result->zeros = holder->field_width;
        else
            result->zeros = holder->precision;
        if (holder->precision < 0 && !holder->field_width)
            result->zeros += 1;
    }
}

void zeros_calculator_neg (t_format *holder, t_result *result, int size)
{
    size--;
    zeros_calculator_normal(holder, result, size);
}
void zeros_calculator(t_format *holder, t_result *result, int size)
{
    if (!result->neg && (ft_atoi(holder->value) > 0))
        zeros_calculator_normal (holder, result, size);
    else if (result->neg)
        zeros_calculator_neg (holder, result, size);
    else if (!ft_atoi(holder->value))
        zeros_calculator_zero (holder, result);
}

void spaces_calculator_normal (t_format *holder, t_result *result, int size)
{
    if (holder->flags_existence & FW_ZERO)
    {
      
    }
    else
    {
      if (holder->precision > 0
      && ft_abs(holder->field_width) > holder->precision)
	result->spaces = ft_abs(holder->field_width) - holder->precision;
      else if (holder->precision <= 0 && holder->field_width)
      	result->spaces = ft_abs(holder->field_width) - size;
    }
}

/*void spaces_calculator_neg (t_format *holder, t_result *result, int size)
{

}

void spaces_calculator_zero (t_format *holder, t_result *result, int size)
{

}
*/


void spaces_calculator(t_format *holder, t_result *result, int size)
{
    if (!result->neg && (ft_atoi(holder->value) > 0))
        spaces_calculator_normal (holder, result, size);
    //else if (result->neg)
    //  spaces_calculator_neg (holder, result, size);
    //    else if (!ft_atoi(holder->value))
    //  spaces_calculator_zero (holder, result);
    
    /*
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
    else if (holder->field_width > size && holder->field_width && holder->zero)
    {
        result->spaces = holder->field_width - pr_extra;
    }
    */
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
        //holder->field_width *= -1;
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
    r_debugger("%*.*da\n", 4, 4, 0);
    return (0);
}
*/
