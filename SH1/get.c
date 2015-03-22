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

void	get_paths(char *paths, t_env *myenv)
{
	myenv->paths = ft_strsplit(paths, ':');
}

void	get_env(char **env, t_env *myenv)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	myenv->env_size = i;
	myenv->myenv = (char ***)malloc(sizeof(char **) * i);
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
		i++;
	}
	get_paths(myenv->myenv[0][1], myenv);
}
