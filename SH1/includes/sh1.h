/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:47:06 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/06 15:47:32 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

# include <sys/stat.h>
# include <sys/types.h>

# include "libft.h"
# include "get_next_line.h"

typedef struct			s_env
{
	char				***myenv;
	int					env_size;
	char				**paths;
}						t_env;

typedef struct			s_builtin
{
	char				*name;
	int					(*ptr_fnc)(t_env *, char **);
	struct s_builtin	*next;
}						t_builtin;

int						cd(t_env *e, char **args);
int						env(t_env *e, char **args);
int						set_env(t_env *e, char **args);
int						unset_env(t_env *e, char **args);

void					init_buitin(t_builtin **list);

void					print_env(t_env *e);
void					print_paths(t_env *e);

void					get_paths(char *paths, t_env *myenv);
void					get_env(char **env, t_env *myenv);

int						bin(char **args, t_env *e);

#endif
