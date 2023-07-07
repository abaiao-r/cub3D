/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:20:09 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/03 14:49:11 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = (0);
	}
	else if (dst_len >= size)
	{
		dst_len = size;
	}
	return (dst_len + src_len);
}
/*int main(void)
{
	char    first[] = "12345";
	char    last[] = "abc";

	printf("%li\n", strlcat(last, first, 2));
	printf("%s \n", first);
} */