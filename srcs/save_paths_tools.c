/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:59 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 21:31:08 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "paths.h"

char	*get_start(t_list *rooms)
{
	t_list	*tmp;
	t_rooms	*room;
	char	*start;

	tmp = rooms;
	while (tmp)
	{
		room = tmp->content;
		if (room->room == START)
		{
			room->listed = 0;
			start = room->name;
		}
		if (room->room == START)
			room->listed = 0;
		tmp = tmp->next;
	}
	return (start);
}

int		list_len(t_list *names)
{
	t_list	*tmp;
	int		length;

	length = 0;
	tmp = names;
	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	return (length);
}

t_list	*ft_lstdup(t_list *lst)
{
	t_list	*tmp;
	t_list	*new;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		ft_lst_push_back(&new, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
	return (new);
}

t_paths	*ft_lstdup_path(t_paths *lst)
{
	t_paths	*tmp;
	t_paths	*new;

	if ((new = (t_paths*)malloc(sizeof(t_paths))) == NULL)
		return (NULL);
	tmp = lst;
	new->path = tmp->path;
	new->len = tmp->len;
	return (new);
}

void	ft_lst_del_last(t_list **lst)
{
	t_list	*tmp;
	t_list	*temp;

	tmp = *lst;
	temp = NULL;
	while (tmp->next)
	{
		temp = tmp;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		free(tmp);
		if (temp)
			temp->next = NULL;
		else
			*lst = NULL;
	}
}
