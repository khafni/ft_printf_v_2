#include <stdio.h>
#include <stdarg.h>

typedef struct
{
	char *spec;
	int (*f)(va_list);
} specifier;

 
/*
** simple macros deffinition that will be used for
** storing flags states 
*/
typedef struct 

#define ZEROPAD 1
#define SIGN 2
#define PLUS 4
#define SPACE 8
#define LEFT 16
#define SMALL 32
#define SPECIAL 64

/*
** a struct that holds data about the whole format of
** ft_printf including the flags
*/

typedef	struct
{
	char	specifier;
	int		length;
	int		width;
	size_t	presision;
	int		flags;
}	t_format;