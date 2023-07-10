/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:24:22 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 20:06:30 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
/* int main(void)
{
	 char    src[] = "andr";
	char    dst[] = "Silva";
	char	*dest;
	char *teste;

	dest = (char *)malloc(sizeof(char) * 15);

	printf("%ld |%s", ft_strlcpy(dst, src, 11), dst); 
	teste = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
	printf("%s", teste);
}   */