#include "ft_printf.h"
#include <stdio.h>

int main()
{
  //ft_printf("%d %0*.*d %d", 89, 9, 5, 1996, 42);
  //ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
  ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\tok", 7,5, "ABC",15,0);
  printf("\n");
  printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\tok", 7,5, "ABC",15,0);
  //ft_printf("%*.*s\n", 7, 5, "ABC");
  //printf("%*.*s", 7, 5, "ABC");
  return (0);
}
