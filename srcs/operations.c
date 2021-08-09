/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:06:39 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/09 16:00:26 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	swap(t_list *list)
{
	int		tmp;
	t_list	*tmp2;

	if (ft_lst_length(list) > 1)
	{
		tmp = list->value;
		tmp2 = list->next;
		list->value = tmp2->value;
		list = list->next;
		list->value = tmp;
	}
}

void	push(t_list **srclist, t_list **dstlist)
{
	if ((*srclist))
	{
		ft_lst_add_front(dstlist, (*srclist)->value);
		ft_lst_pop_front(srclist);
	}
}
