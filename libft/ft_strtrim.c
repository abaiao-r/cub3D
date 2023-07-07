/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:09:07 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/03 14:23:03 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
	{
		return (0);
	}
	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		start = (i++) + 1;
	}
	if (start >= ft_strlen(s1))
	{
		return ((char *)ft_calloc(sizeof(char), 1));
	}
	i = ft_strlen(s1) - 1;
	while (i && s1[i] && ft_strchr(set, s1[i]))
	{
		end = (i--) - 1;
	}
	return (ft_substr(s1, start, end - start + 1));
}
/* int main(void)
{
	char    str[] = "Andre1234";
	printf("%s", ft_strtrim(str, "e1234"));
	return(0);
} */