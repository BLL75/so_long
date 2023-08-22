/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:20:50 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/19 18:13:39 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next_tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next_tmp = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next_tmp;
	}
	*lst = NULL;
}
