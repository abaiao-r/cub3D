/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:28:06 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/02 20:35:11 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v')
		return (1);
	else
		return (0);
}

/* main to test ft_isspace */
/* int	main(void)
{
	char test_string[] = "  \t\nhello\r\f\vworld  \n\t ";
	int i;
	char c;

	i = 0;
	while ((c = test_string[i]))
	{
		if (ft_isspace(c))
		{
			printf("'%c' is a whitespace character\n", c);
		}
		else
		{
			printf("'%c' is not a whitespace character\n", c);
		}
		i++;
	}

	return (0);
} */