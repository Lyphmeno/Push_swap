/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:15:40 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/17 17:32:25 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_add_back(t_list *list, int newelem)
{
	t_list	*element;
	t_list	*tmp;

	element = ft_calloc(sizeof(*element), 1);
	element->value = newelem;
	element->next = NULL;
	if (list == NULL)
		return (element);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (list);
}
