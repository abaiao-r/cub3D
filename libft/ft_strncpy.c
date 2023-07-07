/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:25:43 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/06/24 16:26:44 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

/* main to test ft_strncpy */
/* int main(void)
{
    char src[] = "Geeksfor";
    char dest[] = "Geeks";

    printf("Before strncpy dest = %s, src = %s\n", dest, src);
    ft_strncpy(dest, src, 5);
    printf("After strncpy dest = %s, src = %s\n", dest, src);
    return 0;  
} */