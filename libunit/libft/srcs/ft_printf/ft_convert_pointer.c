/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:45:49 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/08 19:55:25 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

ssize_t	pf_convert_pointer(va_list *args, t_format *format)
{
	unsigned long long	ptr;

	ptr = va_arg(*args, unsigned long long);
	if (format->plus)
		format->blank = false;
	if (ptr == 0)
	{
		pf_nil_pointer_maths(format);
		return (pf_print_nil_pointer(format));
	}
	pf_pointer_maths(format, ptr);
	if (format->minus)
		return (pf_print_pointer_left(format, ptr));
	return (pf_print_pointer(format, ptr));
}

ssize_t	pf_print_nil_pointer(t_format *format)
{
	char	*print;
	ssize_t	wr;
	size_t	i;

	print = libft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	if (!format->minus)
		libft_memset(print, ' ', format->padlen);
	i = libft_strlcat(print, "(nil)", format->totallen + 1);
	if (format->minus)
		libft_memset(print + i, ' ', format->padlen);
	wr = write(format->fd, print, format->totallen);
	free(print);
	return (wr);
}

ssize_t	pf_print_pointer(t_format *format, unsigned long long ptr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = libft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	libft_memset(print, ' ', format->padlen);
	i = pf_place_pointer_prefix(print, format);
	libft_memset(print + i, '0', format->precisionlen);
	wr = -1;
	itoa = libft_ulltoa_base(ptr, LOWER_HEXA);
	if (itoa)
	{
		i = libft_strlcat(print, itoa, format->totallen + 1);
		wr = write(format->fd, print, format->totallen);
	}
	free(itoa);
	free(print);
	return (wr);
}

ssize_t	pf_print_pointer_left(t_format *format, unsigned long long ptr)
{
	char	*print;
	char	*itoa;
	ssize_t	wr;
	size_t	i;

	print = libft_calloc(format->totallen + 1, sizeof(char));
	if (!print)
		return (-1);
	i = pf_place_pointer_prefix(print, format);
	libft_memset(print + i, '0', format->precisionlen);
	i += format->precisionlen;
	wr = -1;
	itoa = libft_ulltoa_base(ptr, LOWER_HEXA);
	if (itoa)
	{
		libft_strlcat(print, itoa, format->totallen + 1);
		i += format->arglen;
		libft_memset(print + i, ' ', format->padlen);
		wr = write(format->fd, print, format->totallen);
	}
	free(itoa);
	free(print);
	return (wr);
}

size_t	pf_place_pointer_prefix(char *print, t_format *format)
{
	size_t	i;

	if (format->plus)
		libft_strlcat(print, "+", format->totallen + 1);
	if (format->blank)
		libft_strlcat(print, " ", format->totallen + 1);
	i = libft_strlcat(print, "0x", format->totallen + 1);
	return (i);
}
