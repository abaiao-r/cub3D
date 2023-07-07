/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:04:14 by abaiao-r          #+#    #+#             */
/*   Updated: 2022/11/19 16:12:20 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
	{
		return (0);
	}
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/* int main(void)
{
	t_list *teste = NULL;
	int i;
	teste = malloc(sizeof(t_list));
	teste->content = "abcd";
	teste->next = malloc(sizeof(t_list));
	teste ->next->content = "cdef";
	teste->next->next = malloc(sizeof(t_list));
	teste ->next->next->content = "xzy";
	teste->next->next->next = malloc(sizeof(t_list));
	teste ->next->next->next->content = "xzy";
	teste->next->next->next->next = NULL;
	i = ft_lstsize(teste);
	printf("%d\n", i);
} */