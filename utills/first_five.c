/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 02:24:27 by khafni            #+#    #+#             */
/*   Updated: 2020/02/24 02:34:55 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utills.h"

int
	ft_abs(int nb)
{
	int n;

	n = nb;
	if (nb < 0)
		n *= -1;
	return (n);
}

int
	ft_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb = nb * 10 + str[i] - '0';
		if (nb > 9223372036854775807)
			return (neg < 0 ? 0 : -1);
		i++;
	}
	return (neg * nb);
}

int
	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long
	digitlen(long n)
{
	long i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char
	*ft_ltoa(long n)
{
	long m;
	char *str;
	long nb;

	nb = n;
	m = digitlen(n);
	if (!(str = (char *)malloc(m + 1)))
		return (NULL);
	if (nb == 0)
	{
		str[0] = 0 + '0';
	}
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb != 0)
	{
		str[m - 1] = nb % 10 + '0';
		nb /= 10;
		m--;
	}
	str[digitlen(n)] = '\0';
	return (str);
}
