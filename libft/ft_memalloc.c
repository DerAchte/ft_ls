/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:04:36 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/22 16:03:41 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (void*)malloc(sizeof(size_t) * size)))
		return (NULL);
	while (i < size)
		((char*)ret)[i++] = 0;
	return (ret);
}
