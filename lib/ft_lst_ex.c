/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:12:44 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/16 17:14:21 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_min(t_list *list)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = tmp->value;
	while (tmp != NULL)
	{
		if (i > tmp->value)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_lst_max(t_list *list)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = tmp->value;
	while (tmp != NULL)
	{
		if (i < tmp->value)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_lst_mid(t_list *list, t_data *data, int cmin, int cmax)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		tmpmin;
	int		tmpmax;

	tmp2 = list;
	while (list != NULL)
	{
		tmp = tmp2;
		data->mid = list->value;
		tmpmin = 0;
		tmpmax = 0;
		while (tmp != NULL)
		{
			if (data->mid > tmp->value)
				tmpmin++;
			if (data->mid < tmp->value)
				tmpmax++;
			tmp = tmp->next;
		}
		if (tmpmin == cmin && tmpmax == cmax)
			break ;
		list = list->next;
	}
}

void	ft_lst_ex(t_list *list, t_data *data)
{
	int	cmin;
	int	cmax;

	cmin = ft_lst_length(list) / 2;
	cmax = ft_lst_length(list) / 2;
	if (ft_lst_length(list) % 2 == 0)
		cmax -= 1;
	data->min = ft_lst_min(list);
	data->max = ft_lst_max(list);
	ft_lst_mid(list, data, cmin, cmax);
}
