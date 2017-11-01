/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:05 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 18:33:05 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "paths.h"

int		cur_is_listed(char *cur, t_list **newpath)
{
	t_list	*tmp;

	tmp = *newpath;
	while (tmp)
	{
		if (!ft_strcmp(((t_rooms*)(tmp->content))->name, cur))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		branch_exists(t_list *newpath, t_list *paths)
{
	t_list	*tmp_new;
	t_list	*tmp_paths;
	t_rooms	*n_room;
	t_rooms	*p_room;

	tmp_new = newpath->next;
	tmp_paths = paths;
	if (tmp_new)
		n_room = tmp_new->content;
	while (tmp_paths && tmp_new)
	{
		p_room = ((t_paths*)(tmp_paths->content))->path->next->content;
		if (!ft_strcmp(n_room->name, p_room->name))
		{
			if (list_len(newpath) >=
					list_len(((t_paths*)(tmp_paths->content))->path) - 1)
				return (1);
			else
				return (2);
		}
		tmp_paths = tmp_paths->next;
	}
	return (0);
}

int		is_listed(t_list *newpath, t_list *paths)
{
	t_list	*tmp_new;
	t_list	*tmp_paths;
	t_list	*path;
	t_rooms	*n_room;
	t_rooms	*p_room;

	tmp_new = newpath;
	tmp_paths = paths;
	while (tmp_new->next)
		tmp_new = tmp_new->next;
	while (tmp_paths && tmp_new)
	{
		n_room = tmp_new->content;
		path = ((t_paths*)(tmp_paths->content))->path->next->next;
		while (path)
		{
			p_room = path->content;
			if (p_room->room == ROOM && n_room->room == ROOM
					&& !ft_strcmp(n_room->name, p_room->name))
				return (1);
			path = path->next;
		}
		tmp_paths = tmp_paths->next;
	}
	return (0);
}

int		push_path(t_list **newpath, t_list **paths, t_rooms *room)
{
	t_paths	*path;
	t_list	*tmp;

	tmp = *paths;
	if ((path = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		return (0);
	ft_lst_push_back(newpath, ft_lstnew(room));
	path->path = ft_lstdup(*newpath);
	path->len = list_len(*newpath);
	ft_lst_push_back(paths, ft_lstnew(path));
	ft_lst_del_last(newpath);
	return (1);
}
