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
int check_if_null(t_result *result)
{
  if (result->data->specifier == 'x' || result->data->specifier == 'X')
  {
    if (!hex_to_dec(result->value) && (result->data->flags_existence & PRECISION))
    {
      return (1);
    }
  }
  else if(result->data->specifier == 'p')
  {
       if (((result->value[2] == '0')) && result->data->flags_existence & PRECISION)
       {
        ft_putstr_fd("0x", 1);
        return (1);
       }
  }
  else if (!ft_ltoi(result->value) && (result->data->flags_existence & PRECISION))
      return (1);
  return (0);
}

void    p_num(t_result *result)
{
  long n;

  if (check_if_null(result))
  {
      return ;
  }
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
  //if (!ft_ltoi(result->value) && (result->data->flags_existence & PRECISION))
    //return ;
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

void ft_print_max_s(t_result *result)
{
  int m;
  int i;

  i = 0;
  m = result->max_characters;
  while (i < m)
    {
      ft_putchar_fd(result->value[i], 1);
  	  i++;
    }
}

void  p_value(t_result *result)
{
    //if (result->data->specifier == 'd' || result->data->specifier == 'i')
      //p_num(result);
  if (result->data->specifier == 'c')
    ft_putchar_fd(result->data->s_v, 1);
  else if (result->data->specifier == '%')
    ft_putchar_fd('%', 1);
  else if (result->data->specifier == 's')
    ft_print_max_s(result);
  else
    p_num(result);
  //else
    //ft_putstr_fd(result->value, 1);
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
        p_value(result);
        p_spaces(result);
    }
    else if (result->neg && !result->minus)
    {
        p_spaces(result);
    	unsigned_minus_removed(result);
        p_zeros(result);
        p_value(result);
    }
    else if (!result->neg && result->minus)
    {
        p_zeros(result);
        p_value(result);
        p_spaces(result);
    }
    else
    {
        p_spaces(result);
        p_zeros(result);
        p_value(result);
    }
}

int ds_or_not (t_result *result)
{
  if (result->data->specifier == 'c' || result->data->specifier == '%')
    return (1);
  else if (result->value != NULL)
    return (ft_strlen(result->value));
  return (0);
}
int g_parser(va_list alist, char **str_ptr)
{
    int l;
    int len_r;
    //char *pt;
    t_result *result;

    len_r = 0;
    //pt = extractor(*str_ptr);
    result = intreptor(*str_ptr, alist);
    //result = intreptor(pt, alist);
    print_result(result);
    //ft_putstr_fd(result->value, 1);
    l = format_length(*str_ptr) + 1;
    len_r = result->spaces + result->zeros + ds_or_not(result);
    *str_ptr += l;
    //free(pt);
    result_destroy(result);
    return (len_r);
}

int ft_printf(char *str, ...)
{
    va_list alist;

    g_return = 0;
    va_start(alist, str);
    while (*str)
    {
        if (*str == '%')
        {
          g_parser(alist, &str);
        }
        else
        {
            ft_putchar_fd(*str, 1);
        }
        str++;
    }
    va_end(alist);
    return (g_return);
}

/*
int main()
{
 ft_printf("*%s*\n", "ok");
 return (0);
}
*/

/*
int main()
{
  //int i = ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
  //putchar('\n');
  //int j = printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
  //int j = ft_printf("TEST TEST 0000%%%*.*s", 7,5, "ABC");
  ft_printf("|%d%*.*d%d|\n",42, 1, 1, 21, 1337);
  printf("|%d%*.*d%d|\n", 42, 1, 1, 21, 1337);
  //ft_printf("TEST TEST 0000%%%*.*s", 7,5, "ABC");
  return (0);
}
*/

/*
int main()
{

  ft_printf("*%.15x*\n", -1);
  printf("*%.15x*", -1);
  
  return (0);
}
*/