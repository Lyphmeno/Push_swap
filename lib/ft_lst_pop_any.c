/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_any.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:52:32 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/09 15:43:33 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pop_any(t_list **list, int key)
{
	t_list	*tmp;
	t_list	*prev;

	prev = NULL;
	tmp = *list;
	if (list != NULL)
	{
		while (key > 1 && tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			key--;
		}
		prev->next = tmp->next;
	}
	free(tmp);
}
