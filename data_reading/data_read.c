#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
void parser(char *str, va_list alist)
{
    while (*str)
    {
        
        str++;
    }
}
void ft_printf(char *str, ...)
{
    va_list alist;
    va_start(alist, str);
    parser(str, alist);
    va_end(alist);
}