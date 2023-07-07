/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:10:22 by andrefranci       #+#    #+#             */
/*   Updated: 2023/03/03 13:47:20 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(const char *s)
{
	int	i;

	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr_ptr(unsigned long long n, char *base, int j, int fe)
{
	int	i;

	i = 0;
	if (!n && fe == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	if (fe == 0)
	{
		ft_putstr("0x");
		i = i + 2;
	}
	if (n / j > 0)
		i = i + ft_putnbr_ptr(n / j, base, j, 1);
	write(1, &base[n % j], 1);
	i++;
	return (i);
}

static int	ft_putnbr_base(long long int n, char *base, int j)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n / j > 0)
	{
		i = i + ft_putnbr_base(n / j, base, j);
	}
	write(1, &base[n % j], 1);
	i++;
	return (i);
}

static int	format(char s, va_list args)
{
	int	c;

	if (s == 'c')
	{
		c = va_arg(args, int);
		return (write(1, &c, 1));
	}
	else if (s == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (s == 'p')
		return (ft_putnbr_ptr(va_arg(args, long int), "0123456789abcdef", 16,
				0));
	else if (s == 'i' || s == 'd')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 10));
	else if (s == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10));
	else if (s == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				16));
	else if (s == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				16));
	else if (s == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		size;

	va_start(args, s);
	size = 0;
	while (*s)
	{
		if (*s != '%')
		{
			write(1, &*s, 1);
			size++;
		}
		else
		{
			s++;
			size = size + format(*s, args);
		}
		s++;
	}
	va_end(args);
	return (size);
}
/* int	main(void)
{
	int	a;

	printf("%i: ", ft_printf("\nmy func = %d\n", -1));
	printf("\n%i: ", printf("\nmy func = %d\n", -1));

	ft_printf("[%%s]: [%s]\n", "This is a string.");
	printf("[%%s]: [%s]\n", "This is a string.");

	ft_printf("[%%c]: [%c]\n", 'M');
	printf("[%%c]: [%c]\n", 'M');

	ft_printf("[%%d]: [%d]\n", 42);
	printf("[%%d]: [%d]\n", 42);

	ft_printf("[%%x]: [%x]\n", 142);
	printf("[%%x]: [%x]\n", 142);

	ft_printf("[%%p]: [%p]\n", &a);
	printf("[%%p]: [%p]\n", &a);
	return (0);
} */