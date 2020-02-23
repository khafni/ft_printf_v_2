/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 19:24:55 by khafni            #+#    #+#             */
/*   Updated: 2020/02/23 22:51:16 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANALYSER_H
# define ANALYSER_H
# include "../utills/utills.h"
# include "../data_gathering_abstraction/data_gathering.h"

/*
** the struct that i store the result of my data analysis in it
*/

typedef struct	s_result
{
	int			spaces;
	int			max_characters;
	int			zeros;
	int			minus;
	int			neg;
	int			pr_anl;
	char		*value;
	t_format	*data;
}				t_result;

/*
** in my data analysis interface i have different sub data analysers
** depending on which specifier i have to deal with so to minimaize
** the repitation of code i chose to use a function pointer and
** depending on the specifier i use a different sub analyser
*/

typedef void	(*t_intr_f_pt)(t_format *holder, t_result *result);

/*
** function that allocate and inetialize a t_result struct that can be
** passed to other functions
*/

t_result		*result_init(void);

/*
** function that frees the allocated data_gathering and data_result
**  struct pts from the heap and some other variables that are allocated
** in the heap
*/

void			result_destroy(t_result *result);

/*
** function that decides which sub data analyser to use depending
** on what specifier we have to deal with
*/

t_intr_f_pt		which_intreptor (t_format *holder);

/*
** the d and u and i specifier data analyser
*/
void			d_intrepert(t_format *holder, t_result *result);
/*
** the x specifier data analyser
*/
void			x_intrepert(t_format *holder, t_result *result);
/*
** the c and % specifier data analyser
*/
void			c_per_interpret(t_format *holder, t_result *result);
/*
** the s specifier data analyser
*/
void			s_interpret(t_format *holder, t_result *result);

/*
** function that performs a pre analysis on the precision value
** and fill the pr_anl and zeros variables depending on the analysis
** the precision data for the d/u specifier
*/

void			d_precision_handler(t_format *holder,
	t_result *result, int size);

/*
** another d/u/i specifier data analyser that uses the result of the previous
** analyser
*/

void			d_calculator (t_format *holder, t_result *result, int size);

/*
**  the main d/u/i analyser that calls the previous analyser
** and treats some other special cases
*/
void			d_intrepert(t_format *holder, t_result *result);

/*
** main x/X analyser that calls other sub analysers and works in design
** the same  way as the d_intrepert but with slight modifications to work
** for the x/X specifiers
*/

void			x_calculator (t_format *holder, t_result *result, int size);

/*
** the main s specifier data analyser
*/
void			s_interpret(t_format *holder, t_result *result);

/*
** the main % and c specifiers data analyser
*/

void			c_per_interpret(t_format *holder, t_result *result);

/*
** the main data analyser function for all the ft_printf function that calls
** all the other analysers for the right specifiers
*/

t_result		*analyser(char *str, va_list alist);

#endif
