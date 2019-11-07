/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:51:00 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/24 17:39:56 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		size;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhite(s[start]))
	{
		start++;
		if (s[start] == '\0')
			return (ft_strdup(""));
	}
	size = ft_strlen(s + start) - 1;
	while (ft_iswhite(s[size + start]) && size >= 0)
		size--;
	size++;
	return (ft_strsub(s, start, size));
}
