/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:06:39 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/18 16:54:41 by hlevi            ###   ########.fr       */
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

void	push(t_list **srclist, t_list **dstlist, char *str)
{
	if (srclist)
	{
		ft_lst_add_front(dstlist, (*srclist)->value);
		ft_lst_pop_front(srclist);
		ft_putstr_fd(str, 0);
	}
}

void	rotate(t_list **list, int x)
{
	t_list	*tmp;
	t_list	*current;
	t_list	*last;
	int		i;

	if (list)
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (x > ft_lst_length(*list))
			x = x % ft_lst_length(*list);
		x = ft_lst_length(*list) - x;
		current = *list;
		i = 1;
		while (i++ < x && current != NULL)
			current = current->next;
		last = current;
		tmp->next = *list;
		*list = last->next;
		last->next = NULL;
	}
}
