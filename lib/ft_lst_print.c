/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:16:21 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/02 17:12:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *list)
{
	if (!list)
		exit(ft_putstr_fd("Error\nEmpty list\n", 0));
	while (list)
	{
		ft_putstr_fd(ft_itoa(list->value), 0);
		ft_putstr_fd("|", 0);
		list = list->next;
	}
	ft_putstr_fd("\n", 0);
}
