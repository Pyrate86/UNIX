/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 12:13:05 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/10 12:14:10 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		parse(char *cmd, t_builtin *bi_list, t_env *e)
{
	char	**args;
	int		ret;
	char	*err;

	args = ft_strsplitblank(cmd);
	ret = 0;
	err = "";
	while (bi_list)
	{
		if (ft_strcmp(args[0], bi_list->name) == 0)
			ret = bi_list->ptr_fnc(e, args);
		bi_list = bi_list->next;
	}
	if (ret == 0)
	{
		if (ft_strcmp(args[0], "exit") == 0)
			return (0);
		else if (bin(args, e))
			return (1);
		else
		{
			err = ft_strjoin("Command not found : ", args[0]);
			ft_putendl_fd(err, 2);
		}
	}
	return (1);
}

int		main(int ac, char **av, char **env)
{
	char		*line;
	int			running;
	t_builtin	*bi_list;
	t_env		myenv;

	(void)ac;
	(void)av;
	init_buitin(&bi_list);
	get_env(env, &myenv);
	running = 1;
	while (running)
	{
		ft_putstr("\033[94m$>\033[0m");
		get_next_line(0, &line);
		running = parse(line, bi_list, &myenv);
	}
	ft_putendl("\033[95mUntil next time, farewell ...\033[0m");
	return (0);
}
