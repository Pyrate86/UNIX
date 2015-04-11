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

static int		tabsize(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void		get_envsize(t_env *e)
{
	int i;

	i = 0;
	while (e->myenv[i])
		i++;
	e->env_size = i;
}

static int		already_set(t_env *e, char *str)
{
	int i;

	i = 0;
	while (e->myenv[i])
	{
		if (ft_strcmp(e->myenv[i][0], str) == 0)
			return (i);
		i++;
	}
	return (0);
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

int		set_env(t_env *e, char **args)
{
	int	args_size;
	int i;
	char	***nenv;

	args_size = tabsize(args);
	if (args_size > 3)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (args_size > 1)
	{
		i = already_set(e, args[1]);
		if (i)
			e->myenv[i][1] = args[2] ? args[2] : "";			
		else
		{
			nenv = (char ***)malloc(sizeof(char **) * (e->env_size + 2));
			while (i <= e->env_size)
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
					nenv[i][j] = e->myenv[i][j];
					j++;
				}
				i++;
			}
			nenv[e->env_size + 1] = '\0';
			nenv[e->env_size][0] = args[1];
			nenv[e->env_size][1] = args[2] ? args[2] : "";
			free(e->myenv);
			e->myenv = nenv;
			get_envsize(e);
		}
	}
	else
		print_env(e);
	return (3);
}

int		unset_env(t_env *e, char **args)
{
	int	args_size;
	int i;
	int j;
	// char	***nenv;

	args_size = tabsize(args);
	if (args_size < 2)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
	{
		i = 1;
		while (args[i])
		{
			j = 0;
			while (e->myenv[j])
			{
				if (ft_strcmp(e->myenv[j][0], args[i]) == 0)
					ft_putendl(e->myenv[j][0]);
				j++;
			}
			i++;
		}
	}
	return (4);
}
