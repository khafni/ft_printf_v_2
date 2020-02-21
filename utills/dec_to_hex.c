#include "utills.h"

size_t	dec_to_hex_length(size_t n)
{
  int l;

  l = 0;
  while (n)
    {
      n /= 16;
      l++;
    }
  return (l);
}
void	rev_str(char *str, int begin, int end)
{
  char c;

  if (begin >= end)
    return ;
  c = *(str + begin);
  *(str + begin) = *(str + end);
  *(str + end) = c;
  rev_str(str, ++begin, --end);
}

char * h_d_to_a (size_t *ar, int len)
{
  int i;
  char *buf;

  i = 0;
  buf = malloc(len + 1);
  while(i < len)
    {
      if (ar[i] == 10)
	buf[i] = 'a';
      else if (ar[i] == 11)
	buf[i] = 'b';
      else if (ar[i] == 12)
	buf[i] = 'c';
      else if (ar[i] == 13)
	buf[i] = 'd';
      else if (ar[i] == 14)
	buf[i] = 'e';
      else if (ar[i] == 15)
	buf[i] = 'f';
      else
	buf[i] = ar[i] + 48;
      i++;
    }
  buf[i] = '\0';
  free(ar);
  return (buf);
}

char	*dec_to_hex(size_t nb)
{
  size_t *buf;
  int i;
  int len;
  char *str;

  i = 0;
  if (!nb)
    return (ft_strdup("0"));
  len = dec_to_hex_length(nb);
  if(!(buf = malloc (sizeof(size_t)* len)))
    return (NULL);
  while (nb)
    {
      buf[i] = nb % 16;
      nb /= 16;
      i++;
    }
   str = h_d_to_a(buf, len);
  rev_str(str, 0, ft_strlen(str) - 1);
  return (str);
}
