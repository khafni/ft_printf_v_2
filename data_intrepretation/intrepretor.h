#include "../utills/utills.h"
#include "../data_gathering_abstraction/data_gathering.h"
/*
** the struct that i store the result of my data analysis in it
*/
typedef struct
{
  int spaces;
  int max_characters;
  int zeros;
  int minus;
  int neg;
  int pr_anl;
  char *value;
  t_format    *data;
} t_result;

/*
** in my data analysis interface i have different sub data analysers
** depending on which specifier i have to deal with so to minimaize
** the repitation of code i chose to use a function pointer and
** depending on the specifier i use a different sub analyser
*/ 
typedef void  (*intreptor_f_pointer)(t_format *holder, t_result *result);

/*
** function that allocate and inetialize a t_result struct that can be
** passed to other functions
*/

t_result *result_init(void);
/*
** function that frees the allocated data_gathering and data_result
**  struct pts from the heap and some other variables that are allocated
** in the heap
*/
void    result_destroy(t_result *result);

/*
** function that decides which sub data analyser to use depending
** on what specifier we have to deal with
*/
intreptor_f_pointer which_intreptor (t_format *holder)

void zeros_calculator(t_format *holder, t_result *result, int size);
void spaces_calculator(t_format *holder, t_result *result, int size);
void spaces_calculator_neg_zeropad (t_format *holder, t_result *result, int size);
void  d_intrepert(t_format *holder, t_result *result);
void  x_intrepert(t_format *holder, t_result *result);
void  c_per_interpret(t_format *holder, t_result *result);
void	s_interpret(t_format *holder, t_result *result);
void	idk_calculator (t_format *holder, t_result *result, int size);
t_result  *intreptor(char *str, va_list alist);
