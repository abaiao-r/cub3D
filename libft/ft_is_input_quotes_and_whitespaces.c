/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_input_quotes_and_whitespaces.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:45:19 by andrefranci       #+#    #+#             */
/*   Updated: 2023/06/09 15:20:40 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Updates the flag_single_quotes and flag_double_quotes based on the
current character. */
static void	update_quote_flags(char c, int *s_quotes, int *d_quotes)
{
	if (c == '\'' && *d_quotes == 0)
	{
		if (*s_quotes == 0)
			*s_quotes = 1;
		else
			*s_quotes = 0;
	}
	else if (c == '\"' && *s_quotes == 0)
	{
		if (*d_quotes == 0)
			*d_quotes = 1;
		else
			*d_quotes = 0;
	}
}

/* ft_is_input_quotes_and_whitespaces is to determine if a string
contains only quotes and whitespaces.
Function Logic: It iterates through each character, updating quote flags 
accordingly. If a non-whitespace character is found outside of quotes,
it returns 0. Otherwise, if the string consists solely of quotes and 
whitespaces, it returns 1. */
int	ft_is_input_quotes_and_whitespaces(char *str)
{
	size_t	i;
	int		s_quotes;
	int		d_quotes;

	s_quotes = 0;
	d_quotes = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			update_quote_flags(str[i], &s_quotes, &d_quotes);
			i++;
			continue ;
		}
		if ((d_quotes == 0 && s_quotes == 0 && ft_isprint(str[i])
				&& !ft_isspace(str[i])) || ((d_quotes == 1 || s_quotes == 1)
				&& ft_isascii(str[i])))
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	char input1[] = "    ";
	char input2[] = "  A  ";
	char input3[] = "\t\n";
	char input4[] = " \"\" ";
	char input5[] = "\"\" \'\'";
	char input6[] = "\" \"";

	bool result1 = ft_is_input_quotes_and_whitespaces(input1);
	bool result2 = ft_is_input_quotes_and_whitespaces(input2);
	bool result3 = ft_is_input_quotes_and_whitespaces(input3);
	bool result4 = ft_is_input_quotes_and_whitespaces(input4);
	bool result5 = ft_is_input_quotes_and_whitespaces(input5);
	bool result6 = ft_is_input_quotes_and_whitespaces(input6);

	printf("Result 1: %s\n", result1 ? "true" : "false");
	printf("Result 2: %s\n", result2 ? "true" : "false");
	printf("Result 3: %s\n", result3 ? "true" : "false");
	printf("Result 4: %s\n", result4 ? "true" : "false");
	printf("Result 5: %s\n", result5 ? "true" : "false");
	printf("Result 6: %s\n", result6 ? "true" : "false");
	return (0);
} */