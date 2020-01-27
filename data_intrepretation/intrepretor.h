typedef struct
{
    int spaces;
    int max_characters;
    int zeros;
    int minus;
    int left;
    char *value;
} t_result;

/*
** prototypes for the different functions
*/

t_result *result_init(void);
void zeros_calculator(t_format *holder, t_result *result, int size);
void spaces_calculator(t_format *holder, t_result *result, int size);
t_result *intrepert(char *fstr, va_list alist);