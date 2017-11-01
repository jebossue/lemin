/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:54 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 18:32:55 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "paths.h"

static int		explore_room1(t_list *pipes, t_list *tmp, t_list **newpath,
		t_list **paths)
{
	t_rooms	*room1;
	t_rooms	*room2;
	int		ret;

	room1 = ((t_links*)(tmp->content))->room1;
	room2 = ((t_links*)(tmp->content))->room2;
	if (room2->listed == 0 || room2->room == END)
	{
		room1->listed = 1;
		ft_lst_push_back(newpath, ft_lstnew(room1));
		if ((ret = branch_exists(*newpath, *paths)) == 1
				|| is_listed(*newpath, *paths))
			return (2);
		if (room2->room == END)
			return (push_path(newpath, paths, room2));
		if (new_path(pipes, room2->name, newpath, paths) == 1)
			return (1);
		if (*newpath != NULL)
			ft_lst_del_last(newpath);
		return (2);
	}
	return (3);
}

static int		explore_room2(t_list *pipes, t_list *tmp, t_list **newpath,
		t_list **paths)
{
	t_rooms	*room1;
	t_rooms	*room2;
	int		ret;

	room1 = ((t_links*)(tmp->content))->room1;
	room2 = ((t_links*)(tmp->content))->room2;
	if (room1->listed == 0 || room1->room == END)
	{
		room2->listed = 1;
		ft_lst_push_back(newpath, ft_lstnew(room2));
		if ((ret = branch_exists(*newpath, *paths)) == 1
				|| is_listed(*newpath, *paths))
			return (2);
		if (room1->room == END)
			return (push_path(newpath, paths, room1));
		if (new_path(pipes, room1->name, newpath, paths) == 1)
			return (1);
		if (*newpath != NULL)
			ft_lst_del_last(newpath);
		return (2);
	}
	return (3);
}

int				new_path(t_list *pipes, char *cur,
		t_list **newpath, t_list **paths)
{
	t_list	*tmp;

	tmp = pipes;
	while (tmp)
	{
		if (!ft_strcmp(((t_links*)(tmp->content))->room1->name, cur))
		{
			if (cur_is_listed(cur, newpath))
				ft_lst_del_last(newpath);
			if (explore_room1(pipes, tmp, newpath, paths) == 0)
				return (0);
		}
		else if (!ft_strcmp(((t_links*)(tmp->content))->room2->name, cur))
		{
			if (cur_is_listed(cur, newpath))
				ft_lst_del_last(newpath);
			if (explore_room2(pipes, tmp, newpath, paths) == 0)
				return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int				save_paths(t_list *rooms, t_list *links, t_list **paths)
{
	char	*start;
	t_list	*newpath;

	newpath = NULL;
	start = get_start(rooms);
	new_path(links, start, &newpath, paths);
	free(newpath);
	if (!*paths)
		return (0);
	return (1);
}
