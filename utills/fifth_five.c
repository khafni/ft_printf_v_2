
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
  while (i != j)
  {
      tmp = str[i];
      str[i] = str[j];
      str[j] = tmp;
      i++;
      j--;
  }
}
void h_d_to_a (int *str)
{
  
}
int	*dec_to_hex(long n)
{
  int nb;
  int *buf;
  int i;

  i = 0;
  nb = n;
  if(!(buf = malloc (sizeof(int)* (dec_to_hex_length(n) + 1))))
    return (NULL);
  while (nb)
    {
      buf[i] = nb % 16 + 48;
      nb /= 16;
      i++;
    }
  //buf[i] = '\0';
  //rev_str(buf);
  return (buf);
}

int main()
{
  int *ar;

  ar = dec_to_hex(27);

  printf("%d", ar[2]);
  //printf("%s\n", dec_to_hex(27));
  return (0);
}
