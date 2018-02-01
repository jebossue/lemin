/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:37 by jebossue          #+#    #+#             */
/*   Updated: 2018/02/01 17:43:22 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		check_ants(char *line)
{
	int		nbr_ants;

	if (!ft_str_isdigit(line) || !checkintmax(line))
		return (-1);
	nbr_ants = ft_atoi(line);
	if (nbr_ants <= 0)
		return (-1);
	return (nbr_ants);
}

static int		check_error(t_list **rooms, t_list **links, int nbr_ants)
{
	(void)links;
	if (check_rooms(rooms, nbr_ants))
		return (nbr_ants);
	else
		return (0);
}

void			skip_comments(t_list **tab, t_fd *fd)
{
	while (fd->line[0] == '#')
	{
		ft_lst_push_back(tab, ft_lstnew(fd->line));
		get_next_line(fd->fd, &(fd->line));
	}
}

static int		get_inputs(t_list **rooms, t_list **links, t_list **tab,
		t_fd *fd)
{
	int		i;

	i = 0;
	while (get_next_line(fd->fd, &(fd->line)) > 0)
	{
		if (i > 0)
		{
			free(fd->line);
			return (0);
		}
		//ERROR HERE SEG FAULT
		if (!parse_rooms(tab, rooms, fd) ||
				!parse_pipes(tab, links, *rooms, fd))
			return (0);
		free(fd->line);
		i++;
	}
	free(fd->line);
	return (1);
}

int				parse(t_list **rooms, t_list **links, t_list **tab, t_fd *fd)
{
	int		nbr_ants;
	int		ret;

	get_next_line(fd->fd, &(fd->line));
	skip_comments(tab, fd);
	if ((nbr_ants = check_ants(fd->line)) < 0)
	{
		free(fd->line);
		return (-1);
	}
	free(fd->line);
	ft_lst_push_back(tab, ft_lstnew(ft_itoa(nbr_ants)));
	if (!(ret = get_inputs(rooms, links, tab, fd)))
		return (check_error(rooms, links, nbr_ants));
	if (!check_rooms(rooms, nbr_ants))
		return (-1);
	return (nbr_ants);
}
