/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:34:13 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/18 16:54:23 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_front(t_list **list, int newelem)
{
	t_list	*tmp;

	tmp = ft_calloc(sizeof(*tmp), 1);
	tmp->value = newelem;
	tmp->next = *list;
	*list = tmp;
}
