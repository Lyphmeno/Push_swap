/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:38:10 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/22 16:29:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	check_done(t_data *data)
{
	if (check_lst_sort(data->alist) == 1 && (!data->blist))
		return (0);
	else
		return (1);
}

int	check_lst_sort(t_list *list)
{
	t_list	*tmp;
	int		tmpval;

	tmp = list;
	while (tmp->next != NULL)
	{
		tmpval = tmp->value;
		tmp = tmp->next;
		if (tmpval > tmp->value)
			return (0);
	}
	return (1);
}

void	check_dup(t_list *alist, t_data *data)
{
	t_list	*tmplist;

	while (alist->next != NULL)
	{
		tmplist = alist->next;
		while (tmplist != NULL)
		{
			if (tmplist->value == alist->value)
			{
				ft_lst_free(alist);
				free(data);
				ft_exit_code("Error\n", 1);
			}
			tmplist = tmplist->next;
		}
		alist = alist->next;
	}
}

void	parsing_str(char *str, t_data *data)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i] != NULL)
	{
		if (ft_is_digit_char(tmp[i]) == 0)
		{
			i = 0;
			while (tmp[i] != NULL)
				free(tmp[i++]);
			free(tmp);
			ft_lst_free(data->alist);
			free(data);
			ft_exit_code("Error\n", 1);
		}
		data->alist = ft_lst_add_back(data->alist, ft_atoi(tmp[i]));
		i++;
	}
	i = 0;
	while (tmp[i] != NULL)
		free(tmp[i++]);
	free(tmp);
}

void	parsing_base(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 2)
			parsing_str(argv[i], data);
		else
		{
			if (ft_is_digit_char(argv[i]) == 0)
			{
				ft_lst_free(data->alist);
				free(data);
				ft_exit_code("Error\n", 1);
			}
			data->alist = ft_lst_add_back(data->alist, ft_atoi(argv[i]));
		}
		i++;
	}
}
