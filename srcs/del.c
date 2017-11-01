/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:19 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 21:17:08 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "delete.h"

static void	delete_rooms(void *room)
{
	free(((t_rooms*)room)->name);
	free(room);
}

void		delete_paths(void *direction)
{
	t_paths	*path;
	t_paths	*temp;
	t_list	*tmp;
	t_list	*nxt;

	temp = direction;
	path = direction;
	tmp = path->path;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	if (temp)
		free(temp);
}

void		delete_all(t_list **rooms, t_list **links, t_list **paths,
		t_list **tab)
{
	ft_lstdel(tab, &free);
	ft_lstdel(rooms, &delete_rooms);
	ft_lstdel(links, &free);
	ft_lstdel(paths, &delete_paths);
}
