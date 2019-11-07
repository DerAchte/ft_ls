/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:32:08 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/30 14:36:01 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(str) - 1;
	j = 0;
	while (i > j)
	{
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		i--;
		j++;
	}
	return (str);
}
