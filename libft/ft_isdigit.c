/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:55:32 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 19:10:50 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* int	main(void)
{
	char	c;

	c = '5';
	printf("Result when numeric character is passed: %d", ft_isdigit(c));
	c = 'a';
	printf("\nResult when non-numeric character is passed: %d", ft_isdigit(c));
	return (0);
}*/