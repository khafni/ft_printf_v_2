#include "intrepretor.h"

void	s_precision_handler (t_format *holder, t_result *result, int size)
{
  if (holder->precision > 0 && holder->precision < size)
    result->max_characters = holder->precision;
  else
    result->max_characters = size;
}
/*
**  one should always take care from ft_strlen when its input can be a NULL pointer 
**  and protect it with a condition to forbide malfortune 
*/
void	s_interpret(t_format *holder, t_result *result)
{
  int size;

  result->data = holder;
  result->value = ft_strdup(holder->value);
  if (result->value)
    size = ft_strlen(result->value);
  s_precision_handler(holder, result, size);
  if (holder->minus)
    result->minus = 1;
  if (ft_abs(holder->field_width) > result->max_characters)
    result->spaces = holder->field_width - result->max_characters;
  
}
