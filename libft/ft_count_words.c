/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:26:04 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 16:28:02 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] != '\0')
			count++;
		while (!ft_isspace(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}

/* main to test ft_count_words */
/* int main(void)
{
    char str[] = "   Hello   World!  ";
    printf("%d\n", ft_count_words(str));
    return (0);
} */