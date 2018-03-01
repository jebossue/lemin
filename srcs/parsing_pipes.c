/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:43 by jebossue          #+#    #+#             */
/*   Updated: 2018/03/01 11:16:28 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		check_duplicates_links(char **split, t_list *links)
{
	t_list		*links_tmp;
	char		*room1;
	char		*room2;

	links_tmp = links;
	while (links_tmp)
	{
		room1 = ((t_links*)(links_tmp->content))->room1->name;
		room2 = ((t_links*)(links_tmp->content))->room2->name;
		if ((!ft_strcmp(room1, split[0])
				&& !ft_strcmp(room2, split[1]))
				|| (!ft_strcmp(room1, split[1])
				&& !ft_strcmp(room2, split[0])))
			return (0);
		links_tmp = links_tmp->next;
	}
	return (1);
}

static int		check_linked_rooms(t_list *rooms, char **split, t_links **pipe,
		t_list *links)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(((t_rooms*)(tmp->content))->name, split[0]))
		{
			(*pipe)->room1 = tmp->content;
			i++;
		}
		else if (!ft_strcmp(((t_rooms*)(tmp->content))->name, split[1]))
		{
			(*pipe)->room2 = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	if (!check_duplicates_links(split, links))
		return (0);
	return (i);
}

static int		add_links(t_list **links, t_fd *fd, t_list *rooms)
{
	t_links	*pipe;
	char	**split;
	int		i;

	if ((pipe = (t_links*)malloc(sizeof(t_links))) == NULL)
		return (0);
	if (ft_strchr(fd->line, ' '))
		return (0);
	if (!(split = ft_strsplit(fd->line, '-')))
		return (0);
	i = 0;
	while (split[i])
		i++;
	if (i != 2)
		return (delete_split(split));
	i = check_linked_rooms(rooms, split, &pipe, *links);
	delete_split(split);
	if (i == 2)
		ft_lst_push_back(links, ft_lstnew(pipe));
	else
	{
		free(pipe);
		return (0);
	}
	return (1);
}

int				parse_pipes(t_list **tab, t_list **links, t_list *rooms,
		t_fd *fd)
{
	while (fd->line[0] == '#' || (ft_strchr(fd->line, '-')
				&& !ft_strchr(fd->line, ' ')))
	{
		if (ft_strchr(fd->line, '-') && fd->line[0] != '#')
		{
			if (!add_links(links, fd, rooms))
				return (0);
		}
		else if (fd->line[0] != '#')
			return (0);
		ft_lst_push_back(tab, ft_lstnew(fd->line));
		get_next_line(fd->fd, &(fd->line));
	}
	return (1);
}
