/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitblank.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 09:21:11 by ghilbert          #+#    #+#             */
/*   Updated: 2015/03/18 09:21:14 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordnb(char const *str)
{
	int	i;
	int	result;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	result = 0;
	if (str[i] != ' ' && str[i] != '\t')
		result++;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t')
			&& (str[i + 1] != ' ' && str[i + 1] != '\t')
			&& str[i + 1] != '\0')
			result++;
		i++;
	}
	return (result);
}

char		**ft_strsplitblank(char const *s)
{
	char	**splits;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	splits = (char **)malloc(sizeof(char *) * ft_wordnb(s) + 1);
	while (k < ft_wordnb(s))
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i])
			i++;
		j = i;
		while ((s[j] != ' ' && s[j] != '\t') && s[j])
			j++;
		splits[k] = ft_strsub(s, i, (j - i));
		i = j;
		k++;
	}
	splits[k] = 0;
	return (splits);
}
