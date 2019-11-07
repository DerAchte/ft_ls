/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdervil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:18:11 by thdervil          #+#    #+#             */
/*   Updated: 2018/12/01 18:40:46 by thdervil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_lst;

	cur_lst = *alst;
	while (*alst)
	{
		*alst = (*alst)->next;
		ft_lstdelone(&cur_lst, del);
		cur_lst = *alst;
	}
	*alst = NULL;
}
