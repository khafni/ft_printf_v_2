#include <stdio.h>
#include <stdarg.h>

/*
** a struct that holds the specifier and the its corresponding parsing function 
*/
typedef struct
{
	char *specifier;
	int (*)(va_list);
} spc; 
/*
** simple macros deffinition that will be used for
** storing flags states 
*/

#define ZEROPAD 1
#define SIGN 2
#define PLUS 4
#define SPACE 8
#define LEFT 16
#define SMALL 32
#define SPECIAL 64
