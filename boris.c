#include "ft_printf.h"
#include <stdio.h>

int main()
{
  //ft_printf("%d %0*.*d %d", 89, 9, 5, 1996, 42);
  //ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
  //ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\tok", 7,5, "ABC",15,0);
  ft_printf("a%02da", 100);
  printf("\n");
  ft_printf("a%02da", 100);
  /*
	T("%03d", 100);
	T("a%03da", 100);
	T("%04d", 100);
	T("%02d", -100);
	T("%03d", -100);
	T("%05d", -100);
	T("%04d", 0);
	T("%01d", 0);
	T("a%01da", 0);
  */
  //printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\tok", 7,5, "ABC",15,0);
  //ft_printf("%*.*s\n", 7, 5, "ABC");
  //printf("%*.*s", 7, 5, "ABC");
  
  return (0);
}
