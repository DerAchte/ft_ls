/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derachte <derachte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:38:47 by derachte          #+#    #+#             */
/*   Updated: 2019/11/08 19:37:18 by derachte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

# include "libft.h"
# include <stdlib.h>
# include <dirent.h>

typedef	struct	s_files
{
	char			*path;
	struct s_files	*prev;
	struct s_files	*next;
}				t_files;

typedef	struct 	s_opts
{
	char 			opt;
	int				on;
	struct s_opts	*next;
}				t_opts;

typedef	struct	s_ls
{
	t_opts	*opts;
	t_files	*files;
}				t_ls;

t_ls *parse(int ac, char **av);
t_ls *init_ls(int ac, char **av);
t_opts *init_optlist(char *poss);
int fill_optlist(char **av, t_opts *optlst);
int is_illegal(char *arg);
void del_optlst(t_opts **lst);
void clean(t_ls *lst);

#endif