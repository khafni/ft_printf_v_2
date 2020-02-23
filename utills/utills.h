/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:47:39 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 00:48:09 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILLS_H
# define UTILLS_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int g_return;

/*
**	function that "apply" the absolute value on a number
*/
int		ft_abs(int nb);

int format_length (char *s);

long    ft_ltoi(const char *str);

char *extractor(char *format);

/*
** convert from decimal to hexdecimal
*/
char	*dec_to_hex(size_t nb);

/*
**	convert from hex to dec
*/
size_t    hex_to_dec(char *nb);

/*
**	change lowercase letters in a string to uppercase
*/
void	ft_to_lower (char *str);
#endif
