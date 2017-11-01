/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:29 by jebossue          #+#    #+#             */
/*   Updated: 2017/10/31 22:10:16 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELETE_H
# define DELETE_H

# include "parsing.h"

void	delete_all(t_list **rooms, t_list **links, t_list **paths,
		t_list **tab);
void	delete_paths(void *way);

int		delete_split(char **split);

#endif
