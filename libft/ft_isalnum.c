/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:34:21 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 17:15:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z' )
		|| (c >= '0' && c <= '9'));
}
/*int	main(void)
{
	char	c;

	c = '5';
	printf("When numeric character is passed, 
	return value is: %d\n", ft_isalnum(c));

	 c = 'Q';
printf("When uppercase alphabet is passed, 
return value is: %d\n", ft_isalnum(c));

	c = 'l';
	printf("When lowercase alphabet is passed, 
	return value is: %d\n", ft_isalnum(c));

	c = '+';
	printf("When non-alphanumeric character is passed, 
	return value is: %d\n", ft_isalnum(c));
	return (0);
}*/