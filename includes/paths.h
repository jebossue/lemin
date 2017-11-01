/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:33:54 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 12:58:10 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHS_H
# define PATHS_H

int		save_paths(t_list *rooms, t_list *links, t_list **paths);
int		new_path(t_list *pipes, char *cur, t_list **newpath, t_list **paths);

char	*get_start(t_list *rooms);
int		list_len(t_list *names);
t_list	*ft_lstdup(t_list *lst);
t_paths	*ft_lstdup_path(t_paths *lst);
void	ft_lst_del_last(t_list **lst);

int		cur_is_listed(char *cur, t_list **newpath);
int		branch_exists(t_list *newpath, t_list *paths);
int		is_listed(t_list *newpath, t_list *paths);
int		push_path(t_list **newpath, t_list **paths, t_rooms *room);

#endif
