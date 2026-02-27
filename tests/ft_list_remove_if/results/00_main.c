/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2026/02/27 18:02:10 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "tests.h"

int	main(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "basic", test_basic);
	add_test(&test, "empty", test_empty);
	add_test(&test, "remove_all", test_remove_all);
	add_test(&test, "remove_half", test_remove_half);
	add_test(&test, "remove_odd", test_remove_odd);
	add_test(&test, "remove_even", test_remove_even);
	return (run_tests("ft_list_remove_if", test));
}
