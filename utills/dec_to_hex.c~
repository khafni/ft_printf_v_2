#include "utills.h"
long	dec_to_hex_length(long n)
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
void	rev_str(char *str)
{
  char tmp;
  int	i;
  int	j;

  i = 0;
  j = ft_strlen(str) - 1;
  tmp = 0;
  while (i != j && j)
  {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
  }
}
char * h_d_to_a (long *ar, int len)
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
  return (buf);
}
char	*dec_to_hex(long nb)
{
  long *buf;
  int i;
  int len;
  char *str;

  i = 0;
  len = dec_to_hex_length(nb);
  if(!(buf = malloc (sizeof(long)* len)))
    return (NULL);
  while (nb)
    {
      buf[i] = nb % 16;
      nb /= 16;
      i++;
    }
  // rev_long(buf, len);
  printf("\n%d\n", buf[1]);
  str = h_d_to_a(buf, len);
  rev_str(str);
  return (str);
}

int main()
{
  printf("\nnumber in hex: %x*****\n", 24444);
  printf("my hex: %s", dec_to_hex(24444));
  return (0);
}
