/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:41:23 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/22 15:11:23 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

void	print_2Darray(int **array, int i, int size)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < i)
	{
		printf("%d - ", j);
		while (k < size)
		{
			printf("|%d", array[j][k]);
			k++;
		}
		k = 0;
		j++;
		printf("|\n");
	}
}

int	find_newmin(t_list *list, int low)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	i = ft_lst_max(tmp);
	while (tmp != NULL)
	{
		if (i > tmp->value && tmp->value > low)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}

void	fill_last_chunk(t_data *data, int i, int size)
{
	int	j;
	int	k;

	k = ft_lst_length(data->alist) % size;
	j = i - 1;
	while (k < size)
	{
		data->chunks[j][k] = data->chunks[0][0];
		k++;
	}
}

void	fill_chunks(t_data *data, int i, int size)
{
	int	low;
	int	j;
	int	k;
	int	count;

	j = 0;
	count = 1;
	low = ft_lst_min(data->alist);
	data->chunks[0][0] = low;
	k = 1;
	while (j < i)
	{
		while (k < size && count < ft_lst_length(data->alist))
		{
			low = find_newmin(data->alist, low);
			data->chunks[j][k] = low;
			k++;
			count++;
		}
		k = 0;
		j++;
	}
	if (ft_lst_length(data->alist) % size != 0)
		fill_last_chunk(data, i, size);
}

void	get_chunks(t_data *data, int size)
{
	int	i;

	i = ft_lst_length(data->alist) / size;
	if (ft_lst_length(data->alist) % size != 0)
		i++;
	data->chunks = (int **)ft_newarray(size, i, sizeof(int));
	fill_chunks(data, i, size);
}
