#include "ft_printf.h"
#include <stdio.h>

int main()
{
/*
  ft_printf("*%.15u*\n", -1);
  printf("*%.15u*", -1);
*/
  ft_printf("%9.p\n", (void*)9);
  printf("%9.p", (void*)9);  
  return (0);
}
