/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 17:34:21 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 17:46:07 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
		return (ptr);
	if (!(ret = ft_memalloc(size)))
		return (ptr);
	ft_memcpy(ret, ptr, size);
	free(ptr);
	ptr = NULL;
	return (ret);
}
