#include "intrepretor.h"
void	x_precision_handler(t_format *holder, t_result *result, int size)
{
  if (holder->precision > 0 && holder->precision > size)
  {
    result->pr_anl = holder->precision - size;
    result->zeros = holder->precision - size;
  }
  else if (!hex_to_dec(holder->value) && (holder->precision < 0))
    {
      result->zeros += 1;
      result->pr_anl += 1;
    }
}

void	x_zero_case_handler (t_format *holder, int *size)
{
  if (holder->flags_existence & PRECISION)
    *size = 0;
}

void	x_idk_calculator (t_format *holder, t_result *result, int size)
{
  if (!hex_to_dec(holder->value))
    x_zero_case_handler(holder, &size);
  x_precision_handler(holder, result, size);
  if (holder->flags_existence & FW_ZERO)
  {
      if ((!(holder->flags_existence & PRECISION) || holder->precision < 0)
      && holder->field_width > size)
	result->zeros = holder->field_width - size;
      else if (ft_abs(holder->field_width) > size)
	        result->spaces = ft_abs(holder->field_width) - result->pr_anl - size;
  }
  else
  {
    if (ft_abs(holder->field_width) > size)
      result->spaces = ft_abs(holder->field_width) - result->pr_anl - size;
  }
}

void  x_intrepert(t_format *holder, t_result *result)
{
    result->data = holder;
    if (holder->minus)
        result->minus = 1;
    if (holder->field_width < 0)
        result->minus = 1;
    result->value = ft_strdup(holder->value);
    x_idk_calculator(holder, result, ft_strlen(result->value));
}