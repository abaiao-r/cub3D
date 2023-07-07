/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:35:45 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/19 15:46:53 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	i = 0;
	if (!destination && !source)
		return (dest);
	if ((&source[0] < &destination[0]) && (&destination[0] < &source[0] + n))
	{
		while (i < n)
		{
			destination[n - i - 1] = source[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i++ < n)
		{
			*destination++ = *source++;
		}
	}
	return (dest);
}
/* int main(void)
{
	char str1[] = "ABCDE";
	ft_memmove(str1 + 2, str1, 3);
	printf("Copied string is %s", str1);
	return (0);
} */