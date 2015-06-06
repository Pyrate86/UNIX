/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:48:08 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ask_quit(char **new_av, int sock)
{
	(void)new_av;
	(void)sock;
	ft_putendl("SUCCESS");
	exit (0);
	return (-1);
}
