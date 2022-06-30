#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_strchr(const char *s, int c);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_strlen(const char *str);
int	putptr_rec(unsigned long n, char t);
int	putptr(unsigned long n, char t);
int	putdec_rec(int n);
int	putdec(int n);
int	putunsigned(int base, unsigned int n, char c);
int print_specifiers(va_list ptr, char specifier);
int	ft_printf(const char *str, ...);

#endif


