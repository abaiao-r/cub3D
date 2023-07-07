/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:39:01 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/04 15:08:45 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_skip_whitespace(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0' && ft_isspace((*str)[i]))
		++i;
	*str += i;
}

/* int	main(void)
{
	char test_string[] = "  \t\nhello world";
	char *str = test_string;

	ft_skip_whitespace(&str);

	printf("%s\n", str);

	return (0);
} */