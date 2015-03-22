/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 11:46:48 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/18 11:46:57 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	pile_push(t_builtin **list, char *name, int (*ptr_fnc)())
{
	t_builtin *new;

	new = (t_builtin *)malloc(sizeof(t_builtin));
	if (new != NULL)
	{
		new->name = name;
		new->ptr_fnc = ptr_fnc;
		if (*list == NULL)
			new->next = NULL;
		else
			new->next = *list;
		*list = new;
	}
}

void		init_buitin(t_builtin **list)
{
	*list = NULL;
	pile_push(list, "setenv", &(set_env));
	pile_push(list, "unsetenv", &(unset_env));
	pile_push(list, "env", &(env));
	pile_push(list, "cd", &(cd));
}
