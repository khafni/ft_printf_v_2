#include "intrepretor.h"
#include "../utills/utills.h"
void  per_interpret(t_format *holder, t_result *result)
{
    if (holder->flags_existence & FW_ZERO)
    {
        if (holder->field_width > 1 && !holder->minus)
	        result->zeros = holder->field_width - 1;
        else if (holder->field_width < -1 || holder->minus)
            result->spaces = ft_abs(holder->field_width) - 1;
    }
    else
        result->spaces = ft_abs(holder->field_width) - 1;
}
void  c_per_interpret(t_format *holder, t_result *result)
{
    result->data = holder;
    if (holder->minus)
        result->minus = 1;
    if (holder->specifier == 'c')
        result->spaces = ft_abs(holder->field_width) - 1;
    else if (holder->specifier == '%')
        per_interpret(holder, result);
}