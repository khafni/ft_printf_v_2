#include <stdio.h>
#include <stdarg.h>

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
	int		field_width;
	int		precision;
	int 	minus;
	int 	plus;
	int 	hashtag;
	int 	zero;
}	t_format;