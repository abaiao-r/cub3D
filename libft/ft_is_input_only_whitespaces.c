/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_input_only_whitespaces.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:55:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/06/07 20:00:42 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterate through each character in the string until the null 
terminator is encountered.
If a printable character (using ft_isprint) that is not a 
whitespace (using ft_isspace) is found, return 0.
Otherwise, if only whitespaces or non-printable characters are
present, return 1. */
int	ft_is_input_only_whitespaces(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* int main(void)
{
    char input1[] = "    ";
    char input2[] = "  A  ";
    char input3[] = "\t\n";

    bool result1 = ft_is_input_only_whitespaces(input1);
    bool result2 = ft_is_input_only_whitespaces(input2);
    bool result3 = ft_is_input_only_whitespaces(input3);

    printf("Result 1: %s\n", result1 ? "true" : "false");
    printf("Result 2: %s\n", result2 ? "true" : "false");
    printf("Result 3: %s\n", result3 ? "true" : "false");

    return (0);
} */