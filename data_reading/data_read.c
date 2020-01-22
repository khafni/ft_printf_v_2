#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
#include "../libft/libft.h"
void parser(char *str, va_list alist)
{
    while (*str)
    {
        if (*str = '%')
        {
        
        }
        else
        {
            ft_putchar_fd(*str, 1);
        }
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

int main()
{

    return (0);
}