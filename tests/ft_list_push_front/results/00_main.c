/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:56:23 by lcottet           #+#    #+#             */
/*   Updated: 2026/02/25 18:45:22 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit_bonus.h"
#include "tests.h"

int	main(void)
{
	t_test	*test;

	test = NULL;
	add_test(&test, "basic", test_basic);
	add_test(&test, "empty list", test_empty);
	return (run_tests("ft_list_push_front", test));
}
