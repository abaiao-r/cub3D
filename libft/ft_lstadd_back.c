/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:21:22 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/28 16:38:24 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
		{
			*lst = new;
		}
	}
	return ;
}
/* int main(void)
{
	t_list *teste;
	t_list *add;
	t_list *temp;
	
	teste -> content = "abc";
	add -> content = "def";
	ft_lstadd_back(&teste, add);
	while (teste)
	{
		printf("%s\n", (char *)teste -> content);
		teste = teste -> next;
	}
} */