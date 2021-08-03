/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:25:04 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/03 16:03:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pop_front(t_list *list)
{
	t_list	*element;

	if (list == NULL)
		return (list);
	element = list->next;
	free(list);
	return (element);
}
