/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:21 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/13 16:55:34 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t size_dst;
	size_t i;
	size_t i_max;

	i = 0;
	size_dst = ft_strlen(dst);
	i_max = size_dst + size;
	if (size < size_dst)
		return (ft_strlen(src) + size);
	while (src[i] && (size_dst + i) < (size - 1))
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	while (src[i])
		i++;
	return ((size_dst + i));
}
