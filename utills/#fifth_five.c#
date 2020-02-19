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

char	*dec_to_hex(long n)
{
  int nb;
  char *buf;
  int i;

  i = 0;
  nb = n;
  if(!(buf = malloc (dec_to_hex_length(n) + 1)))
    return (NULL);
  while (nb)
    {
      buf[i] = nb % 16 + 48;
      nb /= 16;
      i++;
    }
  buf[i] = '\0';
  return (buf);
}

int main()
{
  printf("%s\n", dec_to_hex(98888));
  return (0);
}
