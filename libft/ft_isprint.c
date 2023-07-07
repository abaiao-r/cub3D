/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:05:06 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/10/29 17:15:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* int main(void)
{
    char c;

    c = 'Q';
    printf("Result when a printable character %c 
    is passed to isprint(): %d", c, ft_isprint(c));

    c = '\n';
    printf("\nResult when a control character %c
     is passed to isprint(): %d", c, ft_isprint(c));

    return (0);
} */