/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:16:21 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/03 14:40:22 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print(t_list *list)
{
	char	*tmp;

	if (!list)
		exit(ft_putstr_fd("Error\nEmpty list\n", 0));
	while (list)
	{
		tmp = ft_itoa(list->value);
		ft_putstr_fd(tmp, 0);
		ft_putstr_fd("|", 0);
		list = list->next;
		free(tmp);
	}
	ft_putstr_fd("\n", 0);
}
