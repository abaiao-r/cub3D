/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:36:16 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 16:36:42 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_isspace(str[i]) == 0)
		i++;
	return (i);
}

/* main to test ft_strlen_word */
/* int main(void)
{
    char str[] = "   Hello   World!  ";
    printf("%d\n", ft_strlen_word(str));
    return (0);
} */