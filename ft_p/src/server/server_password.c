/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_password.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:48:38 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char				*get_log(void)
{
	int		i;
	char	**tmp;
	char	*path;
	char	*exec;

	tmp = ft_strsplit(getenv("_"), '/');
	i = 0;
	path = tmp[0][0] == '.' ? tmp[i++] : "";
	while (tmp[i + 1])
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, tmp[i]);
		i++;
	}
	exec = ft_strjoin(path, "/../.log");
	return (exec);
}

int						server_login(int sock)
{
	int		ret;
	char	buff[1024];
	char	*line;
	int		fd;

	ret = 0;
	line = NULL;
	buff[0] = '\0';
	while (ft_strcmp(buff, "okcbon"))
		ret = recv(sock, buff, 1023, 0);
	send(sock, "wfyl", 4, 0);
	ret = recv(sock, buff, 1023, 0);
	fd = open(get_log(), O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (!(ft_strcmp(line, buff)))
		{
			send(sock, "gotit", 5, 0);
			return (0);
		}
	}
	send(sock, "shameonyou", 10, 0);
	return (-1);
}
