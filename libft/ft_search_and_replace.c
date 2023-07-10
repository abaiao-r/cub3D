/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_and_replace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:38:31 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 15:39:41 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_search_and_replace(char *str, char find, char replace)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
}

/* main to test ft_search_and_replace */
/* int main(void)
{
    char str[] = "Hello World!";
    char find = 'l';
    char replace = 'L';

    ft_search_and_replace(str, find, replace);
    printf("%s\n", str);
    return (0);
} */