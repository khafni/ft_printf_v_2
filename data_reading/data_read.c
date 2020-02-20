#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
#include "data_read.h"
#include "../utills/utills.h"


void p_spaces(t_result *result)
{
    int i;

    i = 0;
    while (i < result->spaces)
    {
        ft_putchar_fd(' ', 1);
        i++;
    }
}

void p_zeros(t_result *result)
{
    int i;

    i = 0;
    while (i < result->zeros)
    {
        ft_putchar_fd('0', 1);
        i++;
    }
}
void    p_num(t_result *result)
{
  long n;

  if (!(result->data->specifier == 'd' || result->data->specifier == 'i'))
    {
      ft_putstr_fd(result->value, 1);
      return ;
    }
  n = -1 * ft_ltoi(result->value);
  if (n == MIN_INTEGER)
  {
    n = 2147483648;
  }
  if (!ft_ltoi(result->value) && (result->data->flags_existence & PRECISION))
    return ;
  else
    {
       if (result->neg && (ft_ltoi(result->value) != MIN_INTEGER))
	 ft_putnbr_long(n);
        else if (ft_ltoi(result->value) == MIN_INTEGER)
	  ft_putnbr_long(2147483648);
	else
	  ft_putstr_fd(result->value, 1);
     }
  (void)n;
}

void unsigned_minus_removed (t_result *result)
{
  char c;

  c = result->data->specifier;
  if (c == 'd' || c == 'i')
      ft_putchar_fd('-', 1);
}

void print_result(t_result *result)
{
    if (result->neg && result->minus)
    {
    	unsigned_minus_removed(result);
        p_zeros(result);
        p_num(result);
        p_spaces(result);
    }
    else if (result->neg && !result->minus)
    {
        p_spaces(result);
    	unsigned_minus_removed(result);
        p_zeros(result);
        p_num(result);
    }
    else if (!result->neg && result->minus)
    {
        p_zeros(result);
        p_num(result);
        p_spaces(result);
    }
    else
    {
        p_spaces(result);
        p_zeros(result);
        p_num(result);
    }
}
int g_parser(va_list alist, char **str_ptr)
{
    int l;
    int len_r;
    char *pt;
    t_result *result;

    len_r = 0;
    pt = extractor(*str_ptr);
    result = intreptor(*str_ptr, alist);
    print_result(result);
    l = format_length(*str_ptr) + 1;
    len_r = result->spaces + result->zeros + ft_strlen(result->value);
    *str_ptr += l;
    free(pt);
    result_destroy(result);
    return (len_r);
}

int ft_printf(char *str, ...)
{
    va_list alist;
    int l;

    g_return = 0;
    l = 0;
    va_start(alist, str);
    while (*str)
    {
        if (*str == '%')
        {
                l += g_parser(alist, &str);
        }
        else
        {
            ft_putchar_fd(*str, 1);
            l++;
        }
        str++;
    }
    va_end(alist);
    return (g_return);
}

int main()
{    
    ft_printf("%.55Xe\n", -1996);
    printf("%.55Xe", -1996);
    return (0);
}

