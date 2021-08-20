/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:10:59 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/19 13:51:34 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	print_change(t_data *data)
{
	ft_putstr_fd("alist = ", 0);
	ft_lst_print(data->alist);
	ft_putstr_fd("blist = ", 0);
	ft_lst_print(data->blist);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (argc < 2)
		ft_exit_code("Error\n", 2);
	parsing_base(data, argc, argv);
	check_dup(data->alist);
	push_base(data);
	print_change(data);
	ft_lst_free(data->alist);
	ft_lst_free(data->blist);
	free(data);
	return (0);
}
