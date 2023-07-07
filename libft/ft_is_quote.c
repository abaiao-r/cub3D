/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:56:44 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/02 22:00:33 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isquote(char c)
{
	return (c == '\'' || c == '\"');
}

/* main to test  */
/* int main(void) 
{
    char c = '"';
    int result = ft_isquote(c);

    if (result)
        printf("%c is a quote character\n", c);
    else
        printf("%c is not a quote character\n", c);
    return (0);
} */