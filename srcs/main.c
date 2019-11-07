/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derachte <derachte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:31:08 by derachte          #+#    #+#             */
/*   Updated: 2019/11/07 23:24:16 by derachte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_illegal(char *arg)
{
	int		i;
	char	*err;
	
	i = 1;
	err = "usage: ls [-@ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1%] [file ...]\n";
	while (arg[i])
	{
		if (!(arg[i] == 'l' || arg[i] == 'R' || arg[i] == 'a' ||
			arg[i] == 'r' || arg[i] == 't'))
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(arg[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd(err, 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

t_opts	*init_optlist(char *poss)
{
	t_opts	*ret;

	ret = NULL;
	if (!poss || !*poss)
		return (ret);
	ret = (t_opts *)malloc(sizeof(t_opts));
	ret->opt = *poss;
	ret->on = 0;
	ret->next = init_optlist(++poss);
	return (ret);
}

int		fill_optlist(char **av, t_opts *optlst)
{
	t_opts	*start;

	start = optlst;
	if (!*av)
		return (0);
	while (*av && *av[0] == '-')
	{
		if (is_illegal(*av) < 0)
			return (-1);
		while (optlst)
		{
			if (ft_cisin(*av, optlst->opt))
				optlst->on = 1;
			optlst = optlst->next;
		}
		optlst = start;
		av++;
	}
	return (0);
}

// void	check_files(int ac, char **av, t_ls *ls)
// {
// 	DIR				*o_dir;
// 	struct dirent	*r_dir;


// }

t_ls	*parse(int ac, char **av)
{
	t_ls *ls;

	ac++;
	ls = init_ls(ac, av);
	return (ls);
}

void	del_optlst(t_opts **lst)
{
	t_opts	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(&tmp->opt);
		free(tmp);
	}
	free(lst);
	lst = NULL;
}


void	clean(t_ls *lst)
{
	if (lst->opts)
		del_optlst(&lst->opts);
}

t_ls	*init_ls(int ac, char **av)
{
	t_ls	*ret;

	(void)ac;
	if (!(ret = (t_ls*)malloc(sizeof(t_ls))))
		return NULL;
	ret->opts = init_optlist("lRart");
	if (fill_optlist(++av, ret->opts) < 0)
	{
		del_optlst(&ret->opts);
		return (NULL);
	}
	ret->files = NULL;
	return (ret);
}

int		main(int ac, char **av)
{
	t_ls	*ls;

	ls = parse(ac, av);
	clean(ls);
	while (1);
}