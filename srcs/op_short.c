/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_short.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:19:40 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/17 17:30:43 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	sa(t_data *data)
{
	swap(data->alist);
	ft_putstr_fd("sa\n", 0);
}

void	sb(t_data *data)
{
	swap(data->blist);
	ft_putstr_fd("sb\n", 0);
}

void	ra(t_data *data)
{
	rotate(&data->alist, ft_lst_length(data->alist));
	ft_putstr_fd("ra\n", 0);
}

void	rb(t_data *data)
{
	rotate(&data->blist, ft_lst_length(data->blist));
	ft_putstr_fd("rb\n", 0);
}

void	rr(t_data *data)
{
	rotate(&data->alist, 1);
	rotate(&data->blist, 1);
	ft_putstr_fd("rr\n", 0);
}
