/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 18:35:15 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/10 18:35:24 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		tabsize(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		cd(t_env *e, char **args)
{
	(void)e;
	(void)args;
	return (1);
}

int		env(t_env *e, char **args)
{
	print_env(e);
	(void)args;
	return (2);
}

#include <stdio.h>

int		set_env(t_env *e, char **args)
{
	(void)e;
	int	args_size;
	int i;
	char	***nenv;

	args_size = tabsize(args);
	(void)args_size;
	nenv = (char ***)malloc(sizeof(char **) * (e->env_size + 1));
	i = 0;
	while (nenv[i])
	{
		nenv[i] = (char **)malloc(sizeof(char *) * 2);
		i++;
	}
	i = 0;
	while (i < e->env_size)
	{
		int j = 0;
		while (j < 2)
		{
			printf("[%d][%d] = %s\n", i, j, e->myenv[i][j]);
			nenv[i][j] = e->myenv[i][j];
			j++;
		}
		i++;
	}
	e->myenv[0][1] = "";
	e->myenv = nenv;
	ft_putstr(nenv[0][1]);
	print_env(e);


	return (3);
}

int		unset_env(t_env *e, char **args)
{
	(void)e;
	(void)args;
	return (4);
}
