/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:14:52 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/29 17:12:20 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((const unsigned char) s1[i] - (const unsigned char) s2[i]);
}

/* int main(void)
{
    const char *str1 = "abc";
    const char *str2 = "abcd";
    int result = ft_strcmp(str1, str2);
    
    printf("Comparison Result: %d\n", result);
    
    return (0);
} */