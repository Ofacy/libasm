/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logfile_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:34:14 by lcottet           #+#    #+#             */
/*   Updated: 2026/02/25 15:36:47 by lcottet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "libunit_bonus.h"

int	open_logfile(t_unit_total *total, char *funcname)
{
	char	*logfile;

	logfile = libft_strjoin(funcname, ".log");
	if (!logfile)
		return (0);
	total->logfd = open(logfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(logfile);
	return (total->logfd);
}
