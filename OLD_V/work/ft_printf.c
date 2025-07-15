#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (!str)
        ft_putstr("(null)");
    while (str[i])
        ft_putchar(str[i++]);
    return (i);
}

void	ft_putnbr(int n, int *i)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		*i += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, i);
		ft_putnbr(nbr % 10, i);
	}
	else
		*i += ft_putchar(nbr + '0');
}

int	print_hex(unsigned int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		i += print_hex(n / 16);
	i += ft_putchar(hex[n % 16]);
	return (i);
}

int ft_printf(const char *str, ... )
{
    va_list va;

    va_start(va, str);
    int len = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            if (str[i + 1] == 's')
            {
                len += ft_putstr(va_arg(va, char *));
                i++;
            }
            else if (str[i + 1] == 'x')
            {
                len += print_hex(va_arg(va, unsigned int));
                i++;   
            }
            else if (str[i + 1] == 'd')
            {
                ft_putnbr(va_arg(va, int), &len);
                i++;
            }
            else
                len += write(1, &str[i], 1);
        }
        else
            len += write(1, &str[i], 1);
        i++;
    }
    va_end(va);
    return (len);
}

int main(int argc, char const *argv[])
{
    ft_printf("%s", "hi");
    return 0;
}
