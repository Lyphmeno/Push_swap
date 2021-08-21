/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_short2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:32:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/21 13:52:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	rra(t_data *data)
{
	rotate(&data->alist, 1);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data)
{
	rotate(&data->blist, 1);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data)
{
	rotate(&data->alist, ft_lst_length(data->alist));
	rotate(&data->blist, ft_lst_length(data->blist));
	ft_putstr_fd("rrr\n", 1);
}
