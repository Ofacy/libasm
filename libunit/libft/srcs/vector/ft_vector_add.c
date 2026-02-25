/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:26:30 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/20 15:17:08 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

int	libft_vector_add(t_vector *v, void *item)
{
	int	status;

	if (!v)
		return (FAILURE);
	if (v->total == v->capacity - 1)
	{
		status = libft_vector_resize(v, v->capacity << 1);
		if (status != FAILURE)
		{
			libft_memcpy(v->ptr + v->size * v->total, item, v->size);
			v->total++;
		}
	}
	else
	{
		libft_memcpy(v->ptr + v->size * v->total, item, v->size);
		v->total++;
		status = SUCCESS;
	}
	return (status);
}
