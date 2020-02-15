#include "libft/libft.h"
#include "data_gathering_abstraction/data_gathering.h"
#include "data_intrepretation/intrepretor.h"
#include "data_reading/data_read.h"
#include "utills/utills.h"
#include <stdint.h>

int main()
{
  printf("%3d\n", 100);
  ft_printf("%3d", 100);
  printf("\n********\n");
  printf("%d\n", 100);
  ft_printf("%d", 100);
  printf("\n********\n");
  printf("%d\n", INT32_MIN);
  ft_printf("%d", INT32_MIN);
  printf("\n********\n");
  printf("%d\n", INT32_MAX + 95);
  ft_printf("%d", INT32_MAX + 95);
  printf("\n********\n");
  printf("%d\n", 0);
  ft_printf("%d", 0);
  printf("\n********\n");
  printf("a%da\n", 100);
  ft_printf("a%da", 100);
  printf("\n********\n");
  printf("a%da\n", INT32_MIN);
  ft_printf("a%da", INT32_MIN);
  printf("\n********\n");
  printf("a%da\n", 0);
  ft_printf("a%da", 0);
  return (0);
}
