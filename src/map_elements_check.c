/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:28:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/07/08 17:02:06 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_elements(t_map *map)
{
    char *elements[6];
    int i;
    int j;
    int num_elements;
    int count_elements;
    char *element;
    int element_len;

    elements[0] = "NO";
    elements[1] = "SO";
    elements[2] = "WE";
    elements[3] = "EA";
    elements[4] = "F";
    elements[5] = "C";
    num_elements = sizeof(elements) / sizeof(elements[0]);

    i = 0;
    count_elements = 0;
    while (i < num_elements)
    {
        element = elements[i];
        element_len = ft_strlen(element);
        j = 0;
        while (j < map->lin)
        {
            ft_skip_whitespace(&map->game_map[j]);
            if (ft_strncmp(map->game_map[j], element, element_len) == 0)
            {
                count_elements++;
            }
            j++;
        }
        i++;
    }
    if (count_elements != num_elements)
    {
        printf("Error: Missing element(s)\n");
        return 0;
    }
    printf("OK\n");
    return (1);
}
