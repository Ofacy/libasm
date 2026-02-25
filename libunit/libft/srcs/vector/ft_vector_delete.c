/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:57:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 15:17:19 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	libft_vector_delete(t_vector *v, size_t index)
{
	int		status;
	void	*start;
	void	*end;

	status = UNDEFINED;
	if (v && index < v->total)
	{
		start = libft_vector_get(v, index);
		end = libft_vector_get(v, v->total - 1);
		libft_memcpy2(start, start + v->size, end);
		v->total--;
		if (v->total == v->capacity >> 2)
			libft_vector_resize(v, v->capacity >> 2);
	}
	return (status);
}
