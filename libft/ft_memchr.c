/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:07:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/30 16:21:57 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == character)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (0);
}
/* int	main(void)
{
	printf("String after |c| is - |%s|\n", 
	(char *)ft_memchr("http://www.tutorialspoint.com", '.', 25));
	printf("String after |c| is - |%s|\n", 
	(char *)memchr("http://www.tutorialspoint.com", '.', 25));
	return (0);
} */