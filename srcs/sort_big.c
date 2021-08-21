/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:42:34 by hlevi             #+#    #+#             */
/*   Updated: 2021/08/21 17:12:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

int	find_newmin(t_list *list, int low) // MARCHE
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

void	print_2Darray(int **array, int i, int size) // MARCHE
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
		printf("|\n");
		j++;
	}
}

void	fill_chunks(t_data *data, int i, int size) // FAKE
{
	int	low;
	int	j;
	int	k;
	int	count;

	j = 0;
	k = 0;
	count = 1;
	low = ft_lst_min(data->alist);
	data->chunks[j][k] = low;
	k = 1;
	printf("/%d", low);
	while (j < i && count < ft_lst_length(data->alist))
	{
		while (k < size && count < ft_lst_length(data->alist))
		{
			low = find_newmin(data->alist, low);
			//printf("/%d", low);
			data->chunks[j][k] = low;
			printf("[%d,%d]=%d\n", j, k, data->chunks[j][k]);
			k++;
			count++;
		}
		k = 0;
		printf("\n");
		j++;
	}
	k = ft_lst_length(data->alist) % size;
	if (k < size && count >= ft_lst_length(data->alist))
	{
		while (k < size)
		{
			printf("k = %d|%d\n", j, k);
			data->chunks[j - 1][k] = 0;
			k++;
		}
	}
	print_2Darray(data->chunks, i, size);
}

void	last_check_chunks(t_data *data, int i, int size) // FUK
{
	int	j;
	int	k;

	k = 0;
	j = data->chunks[i - 1][0];
	printf("j = %d\n", j);
	while (k < size)
	{
		if (data->chunks[i - 1][k] < j)
			data->chunks[i - 1][k] = '\0';
		k++;
	}
}

void	get_chunks(t_data *data, int size) // MARCHE
{
	int	i;

	i = ft_lst_length(data->alist) / size;
	if (ft_lst_length(data->alist) % size != 0)
		i++;
	data->chunks = (int **)ft_newarray(i, size, sizeof(int));
	fill_chunks(data, i, size);
	//last_check_chunks(data, i, size);
	printf("\n%d = %d (%d)\n", ft_lst_length(data->alist), i, size);
	//print_2Darray(data->chunks, i, size);
}
