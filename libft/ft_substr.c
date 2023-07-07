/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:39:03 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/19 13:10:36 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (start >= (unsigned int)ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if ((unsigned int)ft_strlen(s) - start - 1 < (unsigned int)len)
		len = (unsigned int)ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
/* int main(void)
{
	char str[] = "Andre Francisco";
	printf("%s", ft_substr("hola", 4294967295, 18446744045464567));
} */