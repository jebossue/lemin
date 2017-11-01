/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:45 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 13:52:24 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>

# include "libft.h"
# include "lists.h"
# include "delete.h"

# define START	0
# define ROOM	1
# define END	2
# define NO_ERR	-2

int				parse(t_list **rooms, t_list **links, t_list **tab, t_fd *fd);
int				checkintmax(char *str);
int				parse_rooms(t_list **tab, t_list **rooms, t_fd *fd);
int				check_rooms(t_list **rooms, int ants);
int				parse_pipes(t_list **tab, t_list **links, t_list *rooms,
				t_fd *fd);
void			skip_comments(t_list **tab, t_fd *fd);
int				check_rooms(t_list **rooms, int ants);
int				check_duplinks(t_list *links);

#endif
