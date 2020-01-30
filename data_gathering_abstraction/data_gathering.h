#include <stdio.h>
#include <stdarg.h>

#define FW_ZERO 1
#define FIELD_WIDTH 2
#define PLUS 4
#define SPACE 8
#define FS 16
#define PRECISION 32
#define SS 64


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
	char	*value;
	int		flags_existence;
}	t_format;

/*
**	prototypes for functions
*/

char specifier_extractor(char *s);
t_format *data_init(void);
void flags_filler(char *str, t_format *format);
void field_width_getter(char *format, t_format *holder, va_list vlist);
void precision_getter(char *format, t_format *holder, va_list vlist);
t_format *get_data (char *f_sstr, va_list vlist);