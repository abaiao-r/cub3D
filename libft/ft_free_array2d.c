/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:23 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/10 16:47:30 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/* main to test ft_free_array2d */
/* int main(void)
{
    char **array = malloc(sizeof(char *) * 3);
    array[0] = strdup("Hello");
    array[1] = strdup("World");
    array[2] = NULL;

    ft_free_array2d(array);
    return (0);
} */