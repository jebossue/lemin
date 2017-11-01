/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:11 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 21:14:08 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int				check_rooms(t_list **rooms, int ants)
{
	t_list	*tmp;
	t_rooms	*room;
	int		begin;
	int		end;

	begin = 0;
	end = 0;
	tmp = *rooms;
	while (tmp)
	{
		room = tmp->content;
		if (room->room == START)
		{
			room->ants = ants;
			begin++;
		}
		else if (room->room == END)
			end++;
		tmp = tmp->next;
	}
	if (begin != 1 || end != 1)
		return (0);
	return (1);
}
