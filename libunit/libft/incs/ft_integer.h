/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:58:54 by ibertran          #+#    #+#             */
/*   Updated: 2026/02/25 15:35:55 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef libft_INTEGER_H
# define libft_INTEGER_H

int		libft_strtoi(const char *ptr, char **endptr);
long	libft_strtol(const char *ptr, char **endptr);
int		libft_abs(int x);
double	libft_absd(double x);
int		libft_isrange(int c, int start, int end);

#endif