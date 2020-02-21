#include "utills.h"

int format_length (char *s)
{
	int length;

	length = 0;
	s++;
	while (*s != 'c' && *s != 's' && *s != 'p' &&
	*s != 'd' && *s != 'i' && *s != 'u' &&
	*s != 'x' && *s != 'X' && *s != '%' && *s)
	{
		length++;
		s++;
	}
	return (length);
}

char *extractor(char *format)
{
	char *holder;
	int l;

	l = format_length(format);
	format++;
	holder = malloc(sizeof(char) * l);
	ft_strlcpy(holder, format, l + 1);
	return (holder);
}

long    ft_ltoi(const char *str)
{
    long			i;
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
		i++;
	}
	return (neg * nb);
}

void	ft_to_lower (char *str)
{
  while(*str)
    {
      if (*str >= 97 && *str <= 122)
	*str -= 32;
      str++;
    }
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}
