
#include "intrepretor.h"

t_result *result_init(void)
{
    t_result *result;

    if (!(result = malloc(sizeof(t_result))))
        return (NULL);
    result->spaces = 0;
    result->max_characters = -1;
    result->zeros = 0;
    result->minus = 0;
    result->neg = 0;
    result->pr_anl = 0;
    result->value = NULL;
    result->data = NULL;
    return (result);
}

void    result_destroy(t_result *result)
{
    free(result->value);
    free(result->data->value);
    free(result->data);
    free(result);
}

intreptor_f_pointer which_intreptor (t_format *holder)
{
    intreptor_f_pointer fp;

    fp = NULL;
    if (holder->specifier == 'd' || holder->specifier == 'i' 
    || holder->specifier == 'u')
        fp = &d_intrepert;
    else if (holder->specifier == 'x' || holder->specifier == 'X')
        fp = x_intrepert;
    return (fp);
}

t_result    *intreptor(char *str, va_list alist)
{
    t_format    *holder;
    t_result    *result;
    intreptor_f_pointer fp;

   
    holder = get_data(str, alist);
    result = result_init();
    fp = which_intreptor(holder);
    fp(holder, result);
    return (result);
}

/*
void r_debugger(char *str, ...)
{
	va_list alist;
	t_result *holder;

	va_start(alist, str);
	holder = intreptor(str, alist);
	ft_putstr_fd(holder->value, 1);
	va_end(alist);
}

.
int main()
{
    r_debugger("%x\n", 1996);
    printf("\n%x\n", 1996);
    return (0);
}

*/