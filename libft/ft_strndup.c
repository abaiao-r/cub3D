/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:29:34 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/02 21:37:25 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	size_t	i;
	char	*duplicated;

	if (!str)
		return (NULL);
	len = 0;
	while (len < n && str[len] != '\0')
		len++;
	duplicated = (char *)malloc(sizeof(char) * (len + 1));
	if (duplicated == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		duplicated[i] = str[i];
		i++;
	}
	duplicated[len] = '\0';
	return (duplicated);
}

/* main to test ft_strndup */
/* int main()
{
    char str[] = "Hello, world!";
    char *duplicated;

    duplicated = ft_strndup(str, 5);
    printf("ft_strndup(\"%s\", 5): %s\n", str, duplicated);
    free(duplicated);

    duplicated = ft_strndup(str, 15);
    printf("ft_strndup(\"%s\", 15): %s\n", str, duplicated);
    free(duplicated);

    duplicated = ft_strndup(str, 20);
    printf("ft_strndup(\"%s\", 20): %s\n", str, duplicated);
    free(duplicated);

    return (0);
} */
