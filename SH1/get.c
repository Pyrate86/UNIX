/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:43:09 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/18 11:43:21 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	get_envsize(char **env, t_env *myenv)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	myenv->env_size = i;
}

void		get_paths(char *paths, t_env *myenv)
{
	myenv->paths = ft_strsplit(paths, ':');
}

void		get_env(char **env, t_env *myenv)
{
	int i;

	get_envsize(env, myenv);
	myenv->myenv = (char ***)malloc(sizeof(char **) * myenv->env_size);
	i = 0;
	while (myenv->myenv[i])
	{
		myenv->myenv[i] = (char **)malloc(sizeof(char *) * 2);
		i++;
	}
	i = 0;
	while (env[i])
	{
		myenv->myenv[i] = ft_strsplit(env[i], '=');
		if ( ft_strcmp(myenv->myenv[i][0], "PATH") == 0)
			get_paths(myenv->myenv[i][1], myenv);
		i++;
	}
}
