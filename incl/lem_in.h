/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:03:05 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/19 21:42:14 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct	s_rooms
{
	int			**paths;
	int			num_of_rooms;
	char		**room_names;
	t_list		*room_name_list;
}				t_rooms;

typedef struct	s_queue
{
	t_list		*first;
	t_list		*last;
}				t_queue;

typedef struct	s_ant
{
	int			n;
	t_list		*path;
}				t_ant;

t_queue			*new_t_queue(void);
int				is_empty(t_queue *queue);
void			push(t_queue *queue, t_list *ta);
t_list			*pop(t_queue *queue);
t_list			*peek(t_queue *queue);
void			delete_paths(void *content, size_t content_size);
void			print_ants(int ants, int start, int end, t_rooms *rooms);
void			remove_ste_connections(t_queue *paths, t_rooms *rooms,\
				int start, int end);
void			find_path_capacity(t_list *paths, int ants);
int				pop_to_visit(t_queue *to_visit);
t_list			*get_connecting_rooms(int visiting, t_rooms *rooms, int end);
void			remove_visited(t_rooms *rooms, int start);
t_list			*get_path(t_rooms *rooms, int end, int *room_pointers);
void			init_path(t_queue **tv, int s, int *rp, t_rooms *r);
t_list			**ft_lst_to_array(t_list *list, int *size);
int				gfp(int *p);
t_list			*get_paths(t_rooms *rooms, int start, int end);
void			sort_paths(t_list **paths);
void			ft_error(int i);
int				ft_lemin_atoi(char *str);
void			ft_one_by_one(char **line);
void			free_split(char **split);
void			add_link_to_list(t_rooms **rooms, char *line);
void			create_rooms(t_rooms **rooms, int *start, int *end);
void			delete_generic(void *content, size_t content_size);
void			add_rooms_to_array(t_rooms **rooms, int *start, int *end);
t_rooms			*init_rooms(void);
void			free_rooms(t_rooms *rooms);
t_list			*new_list(int i);
void			get_room_pointers(int *room_pointers, t_rooms *rooms);
int				free_return(char *line, int i);
#endif
