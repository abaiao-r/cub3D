/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:32:34 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/19 16:10:45 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
	{
		return ;
	}
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/* int main(void)
{
	t_list *teste;
	teste = malloc(sizeof(t_list));
	teste -> content = "abc";
	teste -> next = malloc(sizeof(t_list));
	teste -> next -> content = "def";
	teste -> next -> next = NULL;
	ft_lstdelone(teste, del);
	printf("%s\n", (char *)teste->content);
	printf("%s\n", (char *)teste->next->content);
} */