/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:42:50 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/18 11:43:01 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	print_env(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (e->myenv[i])
	{
		j = 0;
		while (e->myenv[i][j] != 0)
		{
			if (j != 0)
				ft_putstr("=");
			ft_putstr(e->myenv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
