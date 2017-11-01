/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:10 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 12:57:49 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "send.h"

static void		send_path(t_list *path, int ants, int *id)
{
	t_rooms			*room;
	t_rooms			*room_n;

	room = path->content;
	room_n = path->next->content;
	if (room_n->room != END)
		send_path(path->next, ants, id);
	if (room->ants > 0 && (room_n->ants == 0 || room_n->room == END))
	{
		if (room->room == START)
			room_n->ant_id = (*id)++;
		else
			room_n->ant_id = room->ant_id;
		room_n->ants += 1;
		room->ants -= 1;
		ft_printf("L%d-%s ", room_n->ant_id, room_n->name);
	}
}

void			send_ants(t_list *paths, int ants)
{
	t_paths	*path;
	t_list	*ways;
	t_rooms	*room;
	t_list	*end;
	int		id;

	id = 1;
	ways = paths;
	path = ways->content;
	room = path->path->content;
	end = path->path;
	while (end->next)
		end = end->next;
	while (((t_rooms*)(end->content))->ants < ants)
	{
		while (ways)
		{
			path = ways->content;
			send_path(path->path, ants, &id);
			ways = ways->next;
		}
		ft_printf("\n");
		ways = paths;
	}
}
