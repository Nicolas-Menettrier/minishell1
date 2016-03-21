#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	main()
{
  char	*str;
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
