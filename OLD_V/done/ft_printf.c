
#include <unistd.h>
#include <stdarg.h>

int ft_char(char c)
{
    return (write(1, &c, 1));
}

int ft_str(char *s)
{
    int i = 0;

    if (!s)
        return (ft_str("(null)"));
    while (s[i])
        ft_char(s[i++]);
    return (i);
}

void ft_nbr(int n, int *i)
{
    long nbr = n;

    if (nbr < 0)
    {
        *i += ft_char('-');
        nbr *= -1;
    }
    if (nbr >= 10)
    {
        ft_nbr(nbr / 10, i);
        ft_nbr(nbr % 10, i);
    }
    else
        *i += ft_char(nbr + '0');
}

int ft_hex(unsigned int n)
{
    char *hex = "0123456789abcdef";
    int i = 0;

    if (n >= 16)
        i += ft_hex(n / 16);
    i += ft_char(hex[n % 16]);
    return (i);
}

int ft_printf(const char *s, ...)
{
    va_list ap;
    va_start(ap, s);

    int len = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] == '%' && (s[i+1] == 's' || s[i+1] == 'x' || s[i+1] == 'd'))
        {
            if (s[i+1] == 's')
                len += ft_str(va_arg(ap, char *));
            if (s[i+1] == 'x')
                len += ft_hex(va_arg(ap, unsigned int));
            if (s[i+1] == 'd')
                ft_nbr(va_arg(ap, int), &len);
            i++;
        }
        else
            len += ft_char(s[i]);
        i++;
    }
    va_end(ap);
    return (len);
}
