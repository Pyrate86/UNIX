/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:04:35 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/18 16:04:45 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	**threetotowd(t_env *e)
{
	int		i;
	char	**twod;

	i = 0;
	while (e->myenv[i])
		i++;
	twod = (char **)malloc(sizeof(char *) * i);
	i = 0;
	while (e->myenv[i])
	{
		twod[i] = ft_strjoin(e->myenv[i][0], "=");
		twod[i] = ft_strjoin(twod[i], e->myenv[i][1]);
		i++;
	}
	return (twod);
}

void	exec(char *path, char **args, t_env *e)
{
	pid_t	father;

	father = fork();
	if (father == -1)
		return ;
	else if (father == 0)
	{
		if (execve(path, args, threetotowd(e)) < 0)
			exit (father);
	}
	else
		wait(0);
}

int		bin(char **args, t_env *e)
{
	char		*path;
	struct stat	filestat;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	while (e->paths[i])
	{
		path = ft_strjoin(e->paths[i], "/");
		path = ft_strjoin(path, args[0]);
		if (stat(path, &filestat) >= 0)
		{
			ret++;
			exec(path, args, e);
		}
		i++;
	}
	path = args[0];
	if (stat(path, &filestat) >= 0)
	{
		ft_putstr("filestat.st_mode = ");
		ft_putnbr(filestat.st_mode);
		ft_putchar('\n');
		ret++;
		exec(path, args, e);
	}
	return (ret);
}
