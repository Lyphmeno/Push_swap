/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:25:04 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/09 15:52:35 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lst_pop_front(t_list *list)
// {
// 	t_list	*tmp;

// 	if (list == NULL)
// 		return (list);
// 	tmp = list;
// 	list = list->next;
// 	free(tmp);
// 	return (list);
// }

void	ft_lst_pop_front(t_list **list)
{
	t_list	*tmp;

	if (list != NULL)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}
