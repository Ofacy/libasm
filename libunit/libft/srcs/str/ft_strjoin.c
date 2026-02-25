/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:01 by ibertran          #+#    #+#             */
/*   Updated: 2023/11/11 17:14:56 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*libft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = libft_strlen(s1);
	if (s2)
		len2 = libft_strlen(s2);
	ptr = libft_calloc(len1 + len2 + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	libft_strlcpy(ptr, s1, len1 + len2 + 1);
	libft_strlcat(ptr, s2, len1 + len2 + 1);
	return (ptr);
}
