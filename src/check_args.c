/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:32:41 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/08 15:24:19 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*  check_args: checks if the terminal input to run the program is wrong.
 *  It checks if the number of arguments is 2.
 *  Then checks if the second argument first 4 characters are
 *  /maps and the last 4 are .cub.
 *  Also checks if the file exists.
 *  @param argc: number of arguments.
 *  @param argv: arguments.
 *  @return: 1 if the arguments are correct, 0 if not.
 */
int	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Usage: ./cub3D <maps/map.cub>\n", 31);
		return (0);
	}
	else
	{
		if (strncmp(argv[1], "maps/", 5) != 0 || strncmp(argv[1]
				+ strlen(argv[1]) - 4, ".cub", 4) != 0)
		{
			write(2, "Usage: ./cub3d <maps/map.cub>\n", 31);
			return (0);
		}
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: %s\n", strerror(errno));
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

/* main to test check_args */
/* int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	if (!check_args(argc, argv))
		return (0);
} */