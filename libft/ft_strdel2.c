/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derachte <derachte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:47:45 by thdervil          #+#    #+#             */
/*   Updated: 2019/10/27 14:25:47 by derachte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel2(char **as)
{
	int		i;
	char	*tmp;

	i = 0;
	if (as)
	{
		while (as[i])
		{
			tmp = as[i];
			i++;
			free(tmp);
			tmp = NULL;
		}
		free(as);
		as = NULL;
	}
}
