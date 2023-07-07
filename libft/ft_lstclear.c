/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:20:06 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/19 16:10:17 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/* 	int main(void)
{
	t_list **tmp;
	*tmp = malloc(sizeof(t_list));
	(*tmp) -> content = "abc";
	(*tmp) -> next = malloc(sizeof(t_list));
	(*tmp) -> next -> content = "def";
	(*tmp) -> next -> next = NULL;
	ft_lstclear(&*tmp, del);
	printf("%s\n", (char *)(*tmp)->content);
} */