/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:21 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:46:56 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		k = i;
		while ((s1[k] == s2[j]) && k < n)
		{
			k++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
