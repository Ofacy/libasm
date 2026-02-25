/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:09:37 by ibertran          #+#    #+#             */
/*   Updated: 2026/02/25 15:38:18 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"
# include "ft_vector.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define GNL_EOF 2
# define GNL 1

int	get_next_line(int fd, char **line);

#endif