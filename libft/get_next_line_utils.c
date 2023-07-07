/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:17:52 by andrefranci       #+#    #+#             */
/*   Updated: 2023/03/15 15:29:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	free(s1);
	return (str);
}

int	stash_organizer(char *stash)
{
	int	i;
	int	j;
	int	isnewline;

	i = 0;
	j = 0;
	isnewline = 0;
	while (stash[i])
	{
		if (isnewline)
		{
			stash[j++] = stash[i];
		}
		if (stash[i] == '\n')
		{
			isnewline = 1;
		}
		stash[i++] = '\0';
	}
	return (isnewline);
}

//main para testar stash_organizer
/* int main (void)
{
	char stash[] = "\0André\nFrancis\0co";
	printf ("%i", stash_organizer(stash));
	printf("%s", stash);
} */
//main para testar ft_strjoin
/* int	main(void)
{
	char	str1[] = "Andre";
	char	str2[] = "Francisco";

	printf("ft_strjoin %s\n", ft_strjoin(str1, str2));
} */