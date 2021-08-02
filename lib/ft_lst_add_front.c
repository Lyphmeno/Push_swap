/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:34:13 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/02 17:25:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_add_front(t_list *list, int newelem)
{
	t_list	*element;

	element = ft_calloc(sizeof(*element), 1);
	element->value = newelem;
	if (!list)
		element->next = NULL;
	else
		element->next = list;
	return (element);
}
