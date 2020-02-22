#include "data_gathering_abstraction/data_gathering.h"
#include "data_intrepretation/intrepretor.h"
#include "data_reading/data_read.h"
#include "utills/utills.h"
#include <stdint.h>

int main()
{
  int i = ft_printf("*%*.*s*\n",5, 2 ,"ABC");
  int j = printf("*%*.*s*" ,5, 2, "ABC");
  printf("\nmy return : %d \ntheir return : %d", i, j);
  //printf("*%*.*s*" ,7, 2, "ABC");
  //printf("*%s*", "ok");
  return (0);
}
