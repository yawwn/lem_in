/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:08:36 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 19:45:28 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int				gfp(int *p)
{
	return (*p);
}

static void		visit(int visiting, t_rooms *rooms)
{
	rooms->paths[visiting][visiting] = rooms->paths[visiting][visiting] | 1;
}

void			get_room_pointers(int *room_pointers, t_rooms *rooms)
{
	int	i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		room_pointers[i] = i;
		i++;
	}
}

static t_list	*get_augmenting_path(t_rooms *rooms, int start,\
										int end, int *room_pointers)
{
	t_list	*path;
	t_queue	*to_visit;
	t_list	*i;
	int		room;
	t_list	*connecting_rooms;

	init_path(&to_visit, start, room_pointers, rooms);
	while (!is_empty(to_visit))
	{
		room = pop_to_visit(to_visit);
		connecting_rooms = get_connecting_rooms(room, rooms, end);
		i = connecting_rooms;
		while (i)
		{
			if (gfp((int *)i->content) != end || room_pointers[end] == end)
				room_pointers[gfp((int *)i->content)] = room;
			visit(gfp((int *)i->content), rooms);
			push(to_visit, new_list(gfp((int *)i->content)));
			i = i->next;
		}
		ft_lstdel(&connecting_rooms, &delete_generic);
	}
	path = get_path(rooms, end, room_pointers);
	free(to_visit);
	return (path);
}

t_list			*get_paths(t_rooms *rooms, int start, int end)
{
	t_queue	*paths;
	t_list	*paths_list;
	t_list	*ta;
	int		*room_pointers;

	rooms->paths[start][start] = 1;
	paths = new_t_queue();
	remove_ste_connections(paths, rooms, start, end);
	room_pointers = (int *)malloc(sizeof(int) * rooms->num_of_rooms);
	get_room_pointers(room_pointers, rooms);
	while ((ta = get_augmenting_path(rooms, start,\
				end, room_pointers)) != NULL)
	{
		push(paths, ta);
		remove_visited(rooms, start);
	}
	free(room_pointers);
	paths_list = peek(paths);
	free(paths);
	return (paths_list);
}
