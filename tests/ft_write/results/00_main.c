/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2026/02/25 16:07:56 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "tests.h"

int	main(void)
{
	t_test	*test;

	test = NULL;
	add_test_param(&test, "basic", test_basic, param_init(1, "Hello, World!\nThis is a test of ft_write.\n", -1));
	add_test_param(&test, "invalid fd", test_invalid_fd, param_init(1, "", -1));
	add_test_param(&test, "invalid fd with errno check", test_invalid_fd_errno, param_init(1, "", -1));
	return (run_tests("ft_write", test));
}
