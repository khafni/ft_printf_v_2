#include "ft_printf.h"

int main()
{
  ft_printf("%d %0*.*d %d", 89, 9, 5, 1996, 42);
  return (0);
}
