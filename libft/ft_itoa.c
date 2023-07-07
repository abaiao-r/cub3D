/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:41 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/07 18:15:58 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_0(int n)
{
	int	size;

	size = 0;
	if (n > 0)
	{
		size = 0;
	}
	else
	{
		size = 1;
	}
	return (size);
}

static int	ft_signal(int n)
{
	int	signal;

	signal = 0;
	if (n < 0)
	{
		signal = -1;
	}
	else
	{
		signal = 1;
	}
	return (signal);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	size;

	size = ft_size_0(n);
	nbr = (long)n * ft_signal(n);
	while (n)
	{
		n = n / 10;
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}
/*int	main(void)
{
	printf("%s\n", ft_itoa(13435));
}*/