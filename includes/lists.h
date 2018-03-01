/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:35 by jebossue          #+#    #+#             */
/*   Updated: 2018/03/01 12:01:37 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

typedef struct	s_fd
{
	int			fd;
	char		*line;
}				t_fd;

typedef struct	s_rooms
{
	int			room;
	char		*name;
	int			ants;
	int			listed;
	int			ant_id;
}				t_rooms;

typedef struct	s_links
{
	t_rooms		*room1;
	t_rooms		*room2;
}				t_links;

typedef struct	s_paths
{
	t_list		*path;
	int			len;
}				t_paths;

#endif
