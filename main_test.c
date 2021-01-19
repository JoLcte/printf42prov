#include <unistd.h>
#include <stdarg.h>

int pf_printf(char *format, ...)
{
    va_list p;
    int ans;

    va_start(p, format);
    ans = 0;
    while (*format)
    {
        if (*format == '%')
            ;   //do some stuff
       write(1, format++, 1);
        ++ans;
    }
    return (ans);
}

int main (int ac, char **av)
{

    int i = pf_printf(av[1], av + 2);
    return (i);
}
