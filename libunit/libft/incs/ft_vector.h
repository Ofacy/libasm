/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:20:58 by ibertran          #+#    #+#             */
/*   Updated: 2026/02/25 15:35:55 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft_VECTOR_H
# define libft_VECTOR_H

# include <stddef.h>
# include <stdbool.h>

# define VECTOR_INIT_CAPACITY 8
# define UNDEFINED -1
# define FAILURE -1
# define SUCCESS 0

typedef struct s_vector
{
	void			*ptr;
	size_t			size;
	size_t			capacity;
	size_t			total;
}	t_vector;

int		libft_vector_add(t_vector *v, void *item);
int		libft_vector_delete(t_vector *v, size_t index);
int		libft_vector_free(t_vector *v);
int		libft_vector_init(t_vector *v, size_t item_size);
int		libft_vector_join(t_vector *v, void *items, size_t n);
int		libft_vector_resize(t_vector *v, size_t capacity);
int		libft_vector_set(t_vector *v, size_t index, void *item);
int		libft_vector_trim(t_vector *v, size_t capacity);
void	*libft_vector_get(t_vector *v, size_t index);

#endif