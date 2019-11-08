/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <thdervil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:24:43 by thdervil          #+#    #+#             */
/*   Updated: 2019/11/02 15:52:18 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int i)
{
	char	*ret;
	int		j;

	j = 0;
	if (!s1 || !*s1)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * i + 2)))
		return (NULL);
	while (j <= i)
	{
		ret[j] = s1[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
