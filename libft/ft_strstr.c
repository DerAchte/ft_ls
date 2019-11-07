/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:49:33 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/30 14:30:10 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	size_t	size;

	i = 0;
	if (!needle[i] && !haystack[i])
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, size) == 0)
			return (&((char*)haystack)[i]);
		i++;
	}
	return (NULL);
}
