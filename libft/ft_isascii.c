/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:35:12 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 17:15:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*int main(void)
{
	char	c;

	c = ' ';
	printf("When any character  between 0 and 127 (inclusive) of 
    ascii table is passed, return value is: %d\n", ft_isascii(c));

	c = 128;
	printf("When character  is not between 0 and 127 (inclusive) 
    of ascii table is passed, return value is: %d\n", ft_isascii(c));
	return (0);
}*/