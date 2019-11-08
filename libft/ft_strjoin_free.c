/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:37:35 by thdervil          #+#    #+#             */
/*   Updated: 2018/12/20 17:26:00 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char *ret;

	if (!(ret = ft_strjoin(s1, s2)))
		return (NULL);
	if (flag == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
		return (ret);
	}
	else if (flag == 2)
	{
		ft_strdel(&s2);
		return (ret);
	}
	else if (flag == 1)
	{
		ft_strdel(&s1);
		return (ret);
	}
	else
		return (ret);
}
