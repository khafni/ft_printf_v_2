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
/*
int  fw_filler (t_format *holder, t_result *result, int size)
{
  int n;

  n = 0;

}
*/


void	zero_case_handler (t_format *holder, int *size)
{
  if (holder->flags_existence & PRECISION)
    *size = 0;
  // if (holder->precision <= 0 && holder->field_width <= 0)
  //result->zeros = 1;
  
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
      //else if ((holder->flags_existence & PRECISION)
      //&& ft_abs(holder->field_width) > size)
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
/*
void zeros_calculator_normal (t_format *holder, t_result *result, int size)
{
  if (holder->precision > 0 && !(holder->flags_existence & FW_ZERO))
    result->zeros = holder->precision - size;
  else if (holder->flags_existence & FW_ZERO)
    {
      if ((holder->precision > 0) && holder->field_width > 0)
	result->zeros = holder->precision - size;
      else if ((holder->precision > 0) && holder->field_width <= 0)
	result->zeros = holder->precision - size;
      else if (holder->precision < 0 && holder->field_width > 0)
	result->zeros = holder->field_width - size;
      else if (!holder->precision && holder->field_width > 0)
	result->zeros = holder->field_width - size;
    }
}

void zeros_calculator_zero (t_format *holder, t_result *result)
{
    if (!(holder->flags_existence & FW_ZERO))
    {
      //    if (holder->precision < 0)
      //    result->zeros = 1;
        if (holder->precision > 0)
	  result->zeros = holder->precision;
    }
    else if (holder->flags_existence & FW_ZERO)
    {
        if (holder->precision < 0)
            result->zeros = holder->field_width;
        else
            result->zeros = holder->precision;
        //if (holder->precision < 0 && !holder->field_width)
	//   result->zeros += 1;
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
    //  printf("\n***%d***\n", result->zeros);
}

void spaces_calculator_normal (t_format *holder, t_result *result, int size)
{
    if (holder->flags_existence & FW_ZERO)
    {
      if (holder->precision > 0
      && ft_abs(holder->field_width) > holder->precision)
	result->spaces = ft_abs(holder->field_width) - holder->precision;
      else if (!holder->precision && holder->field_width < 0)
	result->spaces = ft_abs(holder->field_width) - size;
      else if (holder->precision < 0 && holder->field_width < -1)
	result->spaces = ft_abs(holder->field_width) - size;
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


void spaces_calculator_neg (t_format *holder, t_result *result, int size)
{
  if (holder->flags_existence & FW_ZERO)
    spaces_calculator_neg_zeropad(holder, result, size);
      else
    {
      if (holder->precision > 0
	  && ft_abs(holder->field_width) > holder->precision)
	result->spaces = ft_abs(holder->field_width) - holder->precision - 1;
      else if (holder->precision <= 0 && holder->field_width)
      	result->spaces = ft_abs(holder->field_width) - size;
    }  
}

void spaces_calculator_neg_zeropad (t_format *holder, t_result *result, int size)
{
    if (holder->precision > 0 && holder->precision < size
	&& ft_abs(holder->field_width) > size)
      result->spaces = ft_abs(holder->field_width) - size;
    else if (holder->precision > 0 && holder->precision >= size
	&& ft_abs(holder->field_width) > size)
      result->spaces = ft_abs(holder->field_width) - size - result->zeros;
    else if (holder->precision <= 0 && holder->field_width < 0)
    {
      result->spaces =ft_abs(holder->field_width) - size;
    }
  //else if (!holder->precision)
  //	result->spaces = ft_abs(holder->field_width) - size;
  //  else if (holder->precision < 0 && holder->field_width < -1)
  //	result->spaces = ft_abs(holder->field_width) - size;
}
void spaces_calculator_zero (t_format *holder, t_result *result, int size)
{
  if (holder->flags_existence & FW_ZERO)
    {
      if (holder->precision >= 0)
	result->spaces = ft_abs(holder->field_width) - holder->precision;
      else if (holder->precision < 0 && holder->field_width < -1)
	result->spaces = ft_abs(holder->field_width) - 1;
    }
  else
    {
      if (holder->precision >= 0
      && ft_abs(holder->field_width) >= holder->precision)
	result->spaces = ft_abs(holder->field_width) - holder->precision;
      else if (holder->precision < 0)
	result->spaces = ft_abs(holder->field_width) - size;
    }
}



void spaces_calculator(t_format *holder, t_result *result, int size)
{
    if (!result->neg && (ft_atoi(holder->value) > 0))
        spaces_calculator_normal (holder, result, size);
    else if (result->neg)
      spaces_calculator_neg (holder, result, size);
    else if (!ft_atoi(holder->value))
      spaces_calculator_zero (holder, result, size);
}
*/

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
    idk_calculator(holder, result, ft_strlen(result->value));
    //precision_handler(holder, result, ft_strlen(result->value));
    //zeros_calculator(holder, result, ft_strlen(result->value));
    //spaces_calculator(holder, result, ft_strlen(result->value));
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
