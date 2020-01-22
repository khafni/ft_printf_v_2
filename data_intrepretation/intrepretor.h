typedef struct
{
    int spaces;
    int max_characters;
    int zeros;
    int minus;
    int left;
} t_result;

/*
** prototypes for the different functions
*/

t_result *result_init(void);
void zeros_calculator(t_format *holder, t_result *result, int size);
