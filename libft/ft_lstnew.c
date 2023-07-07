/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quackson <quackson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:25:13 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/05/01 11:56:56 by quackson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*connect;

	connect = (t_list *)malloc(sizeof(t_list));
	if (!connect)
	{
		return (NULL);
	}
	connect->content = (void *)content;
	connect->next = NULL;
	return (connect);
}

/* int main(void)
{
	char str[] = "teste123teste";
	t_list *teste;
	teste = ft_lstnew((void *)str);
	printf("\n%s\n", (char *)teste->content);
} */