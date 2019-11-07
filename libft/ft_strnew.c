/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:05 by thdervil          #+#    #+#             */
/*   Updated: 2018/11/29 15:35:08 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (i < size + 1)
		result[i++] = 0;
	return (result);
}
