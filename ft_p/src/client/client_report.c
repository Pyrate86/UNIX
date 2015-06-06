/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_report.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:48:16 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			client_report(int n, int cs)
{
	if (n == -1)
		ft_putcolorendl("ERROR", 31);
	if (n == 0 || n == 1)
		ft_putcolorendl("SUCCESS", 32);
	if (n == 4)
		send(cs, "ER1", 3, 0);
	if (n == 5)
		send(cs, "ER2", 3, 0);
	if (n == 2)
		ft_putendl("Usage : get <file> or <dir> [...]");
	if (n == 3)
		ft_putendl("Usage : put <file>");
	return (-1);
}
