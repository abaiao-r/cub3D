/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:11:35 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/04/28 16:36:08 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (0);
	}
	while (lst != NULL)
	{
		if (!lst->next)
		{
			return (lst);
		}
		lst = lst->next;
	}
	return (lst);
}
/* int main(void)
{
	t_list *teste;
	teste = malloc(sizeof(t_list));
	teste -> content = "abc";
	teste -> next = malloc(sizeof(t_list));
	teste -> next -> content = "def";
	teste -> next -> next = NULL;
	teste = ft_lstlast(teste);
	printf("%s\n", (char *)teste->content);
} */