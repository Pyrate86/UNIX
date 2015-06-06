/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:21 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:47:09 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*strnew;
	int		i;

	i = 0;
	strnew = (char *)malloc(sizeof(char) * len + 1);
	if (strnew == NULL || start + len > ft_strlen((char *)s))
		return (NULL);
	if (strnew == NULL || (int)len < 0)
		return (NULL);
	while (len && s[start])
	{
		strnew[i] = s[start];
		start++;
		len--;
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
