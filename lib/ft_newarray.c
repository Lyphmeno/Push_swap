/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:55:58 by lyphmeno          #+#    #+#             */
/*   Updated: 2021/08/21 16:26:35 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_newarray(size_t w, size_t h, size_t size)
{
	void	**array_ptr;
	char	*array_byte;
	size_t	total_size;
	size_t	y;

	if (w == 0 || h == 0 || size == 0)
		return (NULL);
	total_size = (h * sizeof(void *)) + (w * h * size);
	if ((total_size - h * sizeof(void *)) != (w * h * size))
		return (NULL);
	array_ptr = (void **)ft_calloc(total_size, 1);
	ft_memset(array_ptr, 0, total_size);
	array_byte = (char *)array_ptr + h * sizeof(void *);
	y = 0;
	while (y < h)
	{
		array_ptr[y] = array_byte + (y * (w * size));
		y++;
	}
	return (array_ptr);
}
