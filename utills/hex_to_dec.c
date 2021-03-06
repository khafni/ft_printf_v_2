/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 03:07:38 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 03:08:39 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utills.h"

int
	ft_pow(int nb, int power)
{
	int r;
	int n;

	r = 1;
	n = nb;
	while (power)
	{
		r *= n;
		power--;
	}
	return (r);
}

size_t
	hex_to_dec(char *nb)
{
	size_t dec_value;
	size_t i;
	size_t l;

	l = ft_strlen(nb);
	dec_value = 0;
	i = 0;
	nb = nb + ft_strlen(nb) - 1;
	while (i < l)
	{
		if (*nb >= '0' && *nb <= '9')
			dec_value += (*nb - 48) * ft_pow(16, i);
		else if ((*nb >= 'a' && *nb <= 'f') || (*nb >= 'A' && *nb <= 'F'))
			dec_value += (*nb - 87) * ft_pow(16, i);
		nb--;
		i++;
	}
	return (dec_value);
}
