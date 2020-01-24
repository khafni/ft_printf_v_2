#include "../data_gathering_abstraction/data_gathering.h"
#include "../data_intrepretation/intrepretor.h"
#include "../libft/libft.h"

int format_length (char *s)
{
	int length;

	length = 0;
	s++;
	while (*s != 'c' && *s != 's' && *s != 'p' &&
	*s != 'd' && *s != 'i' && *s != 'u' &&
	*s != 'x' && *s != 'X' && *s)
	{
		length++;
		s++;
	}
	return (length);
}

void g_parser(va_list alist, char **str_ptr)
{
    int l;


    l = format_length(*str_ptr);
    **str_ptr += format_length()
}
void ft_printf(char *str, ...)
{
    va_list alist;
    va_start(alist, str);
    while (*str)
    {
        if (*str = '%')
        {
                g_parser(alist, str);
        }
        else
        {
            ft_putchar_fd(*str, 1);
        }
        str++;
    }
    parser(str, alist);
    va_end(alist);
}

int main()
{

    return (0);
}