
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

void r_debugger(char *str, ...)
{
	va_list alist;
	t_result *holder;

	va_start(alist, str);
	holder = d_intrepert(str, alist);
	printf("UwU: %d", holder->pr_anl);
	printf("\nzeros: %d", holder->zeros);
	va_end(alist);
}
/*
int main()
{
    r_debugger("%0*da\n", 10, 42);
    printf("\n%0*da\n", 10, 42);
    return (0);
}
*/
