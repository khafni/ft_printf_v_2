#include "data_gathering_abstraction/data_gathering.h"
#include "data_intrepretation/intrepretor.h"
#include "data_reading/data_read.h"
#include "utills/utills.h"
#include <stdint.h>

int main()
{
  int i = ft_printf("*%*.2s*", -15, "ABC");
  putchar('\n');
  int j = printf("*%*.2s*", -15, "ABC");
  printf("\nmy return : %d \ntheir return : %d", i, j);
  //printf("*%*.*s*" ,7, 2, "ABC");
  //printf("*%s*", "ok");
  return (0);
}
