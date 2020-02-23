#include "ft_printf.h"
#include <stdio.h>

int main()
{
  ft_printf("|%0*.%|", -5);
  putchar('\n');
  printf("|%0*.%|", -5);
  return (0);
}