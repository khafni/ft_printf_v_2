#include "intrepretor.h"
#include "../utills/utills.h"
void  c_per_interpret(t_format *holder, t_result *result)
{
    result->data = holder;
    if (holder->minus)
        result->minus = 1;
    if (holder->specifier == 'c')
        result->spaces = ft_abs(holder->field_width) - 1;
    printf("%d", holder->field_width);
}