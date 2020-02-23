/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_gathering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:31:39 by khafni            #+#    #+#             */
/*   Updated: 2020/02/23 19:19:24 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this interface only functionality is to gather the data (value
** of different flags and their state of existence) between a %
** and a specifier
*/

#ifndef DATA_GATHERING_H
# define DATA_GATHERING_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../utills/utills.h"

/*
** simple macros that can be used to store the state of existence
** of different flags in one int using the bitwise or and checken using
** the bitwise and
*/

# define FW_ZERO 1
# define FIELD_WIDTH 2
# define PLUS 4
# define SPACE 8
# define FS 16
# define PRECISION 32
# define SS 64

/*
** a struct that holds all the data between the % and a specifier
*/

typedef struct	s_format
{
	char		specifier;
	int			field_width;
	int			precision;
	int			minus;
	int			plus;
	int			hashtag;
	int			zero;
	char		*value;
	int			flags_existence;
	char		s_v;
}				t_format;

/*
** function that extract the specifier whenever we reach a % in
** the printf string
*/

char			specifier_extractor(char *s);

/*
** function that checks the state of existence of the zero that
** can be left to the fieldwidth/precision point
*/
void			existence_analyser(char *str, t_format *holder);

/*
** data_init allocates memory for the t_format struct variable
** to create it in the heap and initialize its members
*/

t_format		*data_init(void);
/*
** function that finds out if the field width is negative if
** the - is part of the flags not in the paramters of the ft_printf
*/
void			flags_filler(char *str, t_format *format);
/*
** function that extracts the fieldwidth value
*/
void			field_width_getter(char *format,
				t_format *holder, va_list vlist);
/*
** function that extracts the value of the precision
*/
void			precision_getter(char *format, t_format *holder, va_list vlist);
/*
** a helper function for the s specifier that if given a null pointer
** it returns an allocated string with the value of "(null)"
*/
char			*s_transform_n_sn(char *p);
/*
** function that gets the value of any specifier
*/
void			value_get(t_format *holder, va_list vlist);
/*
** the key function to the data gathering abstraction which gets
** all kinds of data between a % and a specifier and returns
** it as a t_format struct that we can analys after
*/

t_format		*get_data (char *f_sstr, va_list vlist);
#endif
