/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:17:58 by andrefranci       #+#    #+#             */
/*   Updated: 2023/06/13 23:54:49 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
	{
		return (NULL);
	}
	if (!stash[0])
		stash[read(fd, stash, BUFFER_SIZE)] = 0;
	while (stash[0])
	{
		line = ft_strjoin_gnl(line, stash);
		if (!line)
			return (NULL);
		if (stash_organizer(stash) == 1)
			break ;
		if (read(fd, stash, 0) < 0)
		{
			free(line);
			return (NULL);
		}
		stash[read(fd, stash, BUFFER_SIZE)] = 0;
	}
	return (line);
}

/* int	main(void)
{
	char *line;
	int fd1;

	fd1 = open("file_test_gnl.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("T1:%s", line);
	free(line);
} */