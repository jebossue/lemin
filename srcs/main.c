/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:32 by jebossue          #+#    #+#             */
/*   Updated: 2018/02/01 17:37:26 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "paths.h"
#include "send.h"
#include "delete.h"

#include <fcntl.h>
#include <unistd.h>

static void	print_map(t_list *tab)
{
	while (tab)
	{
		ft_printf("%s\n", tab->content);
		tab = tab->next;
	}
	ft_printf("\n");
}

static void	lem_in(t_fd *fd)
{
	t_list	*rooms;
	t_list	*links;
	t_list	*paths;
	t_list	*tab;
	int		nbr_ants;

	rooms = NULL;
	links = NULL;
	paths = NULL;
	tab = NULL;
	if ((nbr_ants = parse(&rooms, &links, &tab, fd)) <= 0 || !links ||
			!save_paths(rooms, links, &paths))
	{
		ft_printf("ERROR\n");
		delete_all(&rooms, &links, &paths, &tab);
		return ;
	}
	close(fd->fd);
	print_map(tab);
	send_ants(paths, nbr_ants);
	delete_all(&rooms, &links, &paths, &tab);
}

int			main(int ac, char **av)
{
	int		i;
	t_fd	fd;

	if (ac < 2)
	{
		fd.fd = 0;
		lem_in(&fd);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if ((fd.fd = open(av[i], O_RDONLY)) < 0)
		{
			ft_printf("Failed to open [%s].\n", av[i]);
			return (-1);
		}
		lem_in(&fd);
		i++;
		if (i < ac)
			ft_printf("\n------------------------------------------------\n\n");
	}
	return (0);
}
