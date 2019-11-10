/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derachte <derachte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:31:08 by derachte          #+#    #+#             */
/*   Updated: 2019/11/10 21:46:51 by derachte         ###   ########.fr       */
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
	int		nb_opt;

	start = optlst;
	nb_opt = 0;
	if (!*av)
		return (0);
	while (*av && *av[0] == '-')
	{
		nb_opt++;
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
	return (nb_opt);
}

int		del_1link(t_files **file_lst)
{
	t_files *cur_lnk;
	int		is_beg;

	is_beg = 0;
	cur_lnk = (*file_lst);
	free((*file_lst)->path);
	free(*file_lst);
	if ((*file_lst)->prev)
	{
		(*file_lst)->next->prev = (*file_lst)->prev;
		(*file_lst)->prev->next = (*file_lst)->next;
	}
	else
		is_beg = 1;
	return (is_beg);
}

void	check_files(t_ls *ls)
{
	DIR				*o_dir;
	t_files			*start;
	int				decale;
	// struct dirent	*r_dir;

	decale = 0;
	start = ls->files;
	while (ls->files)
	{
		if (!(o_dir = opendir(ls->files->path)))
		{
			ft_putstr("ls : ");
			perror(ls->files->path);
			decale = del_1link(&ls->files);
			ls->files = ls->files->next;
			closedir(o_dir);
			continue ;
		}
		closedir(o_dir);
		ls->files = ls->files->next;
	}
	ls->files = decale == 0 ? start : start + 1;
}

void	command(t_ls *ls)
{
	check_files(ls);
}

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
		free(tmp);
	}
	lst = NULL;
}

t_files		*init_filelst(char **av, t_files *link)
{
	t_files	*ret;

	if (!av || !*av)
		return (NULL);
	if (!(ret = (t_files*)malloc(sizeof(t_files))))
		return (NULL);
	ret->path = ft_strdup(*av);
	ret->prev = link;
	ret->next = init_filelst(++av, ret);
	return (ret);
}

void	del_filelst(t_files **lst)
{
	t_files *tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->path);
		free(tmp);
	}
	lst = NULL;
}

void	clean(t_ls *lst)
{
	if (lst->opts)
		del_optlst(&lst->opts);
	if (lst->files)
		del_filelst(&lst->files);
}

t_ls	*init_ls(int ac, char **av)
{
	t_ls	*ret;
	int		nb_opts;

	(void)ac;
	if (!(ret = (t_ls*)malloc(sizeof(t_ls))))
		return NULL;
	ret->error = 0;
	ret->opts = init_optlist("lRart");
	if ((nb_opts = fill_optlist(++av, ret->opts)) < 0)
	{
		del_optlst(&ret->opts);
		ret->error = 1;
		return (NULL);
	}
	av += nb_opts;
	ret->files = init_filelst(av, NULL);
	return (ret);
}

int		main(int ac, char **av)
{
	t_ls	*ls;

	ls = parse(ac, av);
	command(ls);
	if (ls->error)
		exit (EXIT_FAILURE);
	printf("PD\n");
	while (ls->files)
	{
		printf(">> %s\n", ls->files->path);
		ls->files = ls->files->next;
	}
	// clean(ls);
}
