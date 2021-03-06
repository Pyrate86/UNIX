/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:48:10 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	prompt(int sock, char *login)
{
	char	buff[1024];
	char	*print;
	int		ret;

	ret = 0;
	send(sock, "affiche_mon_prompt_steuple_thx_bye", 35, 0);
	if ((ret = recv(sock, buff, 1023, 0)) <= 0)
	{
		ft_putstr("Connection Error\n");
		exit(0);
	}
	buff[ret] = '\0';
	print = buff;
	if (login)
	{
		login = ft_strjoin("[", login);
		login = ft_strjoin(login, "] ");
		print = ft_strjoin(login, buff);
	}
	ft_putcolor(print, 33);
}

int			close_sock(int sock)
{
	close(sock);
	return (0);
}

void		sig_handle(void)
{
	signal(SIGTSTP, SIG_IGN);
}

int			main(int ac, char **av)
{
	int		ret;
	char	*line;
	int		port;
	int		sock;
	char	*login;

	if (ac != 3)
		ft_usage(av[0], " <addr> <port>");
	port = ft_atoi(av[2]);
	sock = client_create_tcp(av[1], port);
	sig_handle();
	if (client_login(sock, &login) == -1)
		return (close_sock(sock));
	while (42)
	{
		prompt(sock, login);
		if ((ret = get_next_line(0, &line)) < 0)
			ft_putcolorendl("ERROR", 94);
		if (ret == 0)
			exit(0);
		else if (line[0] != '\0')
			dial_server(sock, line);
		free(line);
	}
	return (close_sock(sock));
}
