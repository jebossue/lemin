/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:48 by jebossue          #+#    #+#             */
/*   Updated: 2018/03/01 12:48:28 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		check_coords(char **split)
{
	char	*c1;
	char	*c2;
	int		i;

	i = 0;
	c1 = NULL;
	c2 = NULL;
	while (split[i])
		i++;
	if (i != 3)
		return (0);
	if (split[1])
		c1 = split[1];
	if (split[2])
		c2 = split[2];
	if (split[1] && (split[1][0] == '+' || split[1][0] == '-'))
		c1++;
	if (split[2] && (split[2][0] == '+' || split[2][0] == '-'))
		c2++;
	if (!ft_str_isdigit(c1) || !ft_str_isdigit(c2)
			|| !checkintmax(split[1]) || !checkintmax(split[2]))
		return (0);
	return (1);
}

static int		check_splited_room(t_list *rooms, char **split)
{
	t_list	*tmp;

	tmp = rooms;
	if (!split)
		return (0);
	if (!check_coords(split))
		return (delete_split(split));
	if (!rooms)
		return (1);
	while (tmp)
	{
		if (!ft_strcmp(split[0], ((t_rooms*)(tmp->content))->name))
			return (delete_split(split));
		tmp = tmp->next;
	}
	return (1);
}

static int		split_room(t_list **rooms, int room, char *line)
{
	t_rooms	*rm;
	char	**split;

	if ((rm = (t_rooms*)malloc(sizeof(t_rooms))) == NULL)
		return (0);
	split = ft_strsplit(line, ' ');
	if (!split[0] || ft_strchr(split[0], '-')
			|| !check_splited_room(*rooms, split))
	{
		free(rm);
		return (0);
	}
	if ((rm->name = ft_strdup(split[0])) == NULL)
		return (0);
	rm->room = room;
	rm->ants = 0;
	rm->listed = 0;
	ft_lst_push_back(rooms, ft_lstnew(rm));
	delete_split(split);
	return (1);
}

static int		add_room(t_list **rooms, int room, t_fd *fd, t_list **tab)
{
	while (fd->line[0] == '#')
	{
		get_next_line(fd->fd, &(fd->line));
		ft_lst_push_back(tab, ft_lstnew(fd->line));
	}
	if (!split_room(rooms, room, fd->line))
		return (0);
	return (1);
}

int				parse_rooms(t_list **tab, t_list **rooms, t_fd *fd)
{
	while (fd->line[0] == '#' || fd->line[0] == 'L'
			|| ft_strchr(fd->line, ' '))
	{
		ft_lst_push_back(tab, ft_lstnew(fd->line));
		if (!ft_strcmp(fd->line, "##start"))
		{
			if (!add_room(rooms, START, fd, tab))
				return (0);
		}
		else if (!ft_strcmp(fd->line, "##end"))
		{
			if (!add_room(rooms, END, fd, tab))
				return (0);
		}
		else if (ft_strchr(fd->line, ' ') && fd->line[0] != 'L')
		{
			if (!add_room(rooms, ROOM, fd, tab))
				return (0);
		}
		else if (fd->line[0] != '#' || fd->line[0] == 'L')
			return (0);
		get_next_line(fd->fd, &(fd->line));
	}
	return (1);
}
