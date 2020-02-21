#include "intrepretor.h"

void	s_precision_handler (t_format *holder, t_result *result, int size)
{
  if (holder->precision > 0 && holder->precision < size)
    result->max_characters = holder->precision;
  else
    result->max_characters = size;
}
void	s_interpret(t_format *holder, t_result *result)
{
  int size;

  result->data = holder;
  result->value = ft_strdup(holder->value);
  size = ft_strlen(result->value);
  s_precision_handler(holder, result, size);
  if (holder->minus)
    result->minus = 1;
  if (ft_abs(holder->field_width) > result->max_characters)
    result->spaces = holder->field_width - result->max_characters;
  
}
