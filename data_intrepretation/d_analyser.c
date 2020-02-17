#include <stdio.h>
#include "../utills/utills.h"
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
    result->pr_anl = 0;
    result->value = NULL;
    result->data = NULL;
    return (result);
}

void    result_destroy(t_result *result)
{
    free(result->value);
    free(result->data->value);
    free(result->data);
    free(result);
}
void	precision_handler(t_format *holder, t_result *result, int size)
{
  if (result->neg)
    size--;
  if (holder->precision > 0 && holder->precision > size)
  {
    result->pr_anl = holder->precision - size;
    result->zeros = holder->precision - size;
  }
  else if (!ft_atoi(holder->value) && (holder->precision < 0))
    {
      result->zeros += 1;
      result->pr_anl += 1;
    }
}

void	zero_case_handler (t_format *holder, int *size)
{
  if (holder->flags_existence & PRECISION)
    *size = 0;
}

void	idk_calculator (t_format *holder, t_result *result, int size)
{
  if (!ft_atoi(holder->value))
    zero_case_handler(holder, &size);
  precision_handler(holder, result, size);
  if (holder->flags_existence & FW_ZERO)
  {
      if ((!(holder->flags_existence & PRECISION) || holder->precision < 0)
      && holder->field_width > size)
	result->zeros = holder->field_width - size;
      else if (ft_abs(holder->field_width) > size)
	        result->spaces = ft_abs(holder->field_width) - result->pr_anl - size;
  }
  //else if (holder->flags_existence & PRECISION)
  else
  {
    if (ft_abs(holder->field_width) > size)
      result->spaces = ft_abs(holder->field_width) - result->pr_anl - size;
  }
}


t_result *d_intrepert(char *fstr, va_list alist)
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
    idk_calculator(holder, result, ft_strlen(result->value));
    return (result);
}

void r_debugger(char *str, ...)
{
	va_list alist;
	t_result *holder;

	va_start(alist, str);
	holder = intrepert(str, alist);
	printf("UwU: %d", holder->pr_anl);
	printf("\nzeros: %d", holder->zeros);
	va_end(alist);
}
/*
int main()
{
    r_debugger("%0*da\n", 10, 42);
    printf("\n%0*da\n", 10, 42);
    return (0);
}
*/
