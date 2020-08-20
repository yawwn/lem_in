/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_create_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:05:45 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/19 21:50:50 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

static int	is_available(char **line)
{
	ft_one_by_one(line);
	if (!ft_strlen(*line))
	{
		free(*line);
		return (0);
	}
	return (1);
}

static void	add_links(t_rooms **rooms, char *fl, int *start, int *end)
{
	char	*line;

	ft_error(*start == -1 || *end == -1);
	add_rooms_to_array(rooms, start, end);
	add_link_to_list(rooms, fl);
	while (is_available(&line))
		add_link_to_list(rooms, line);
}

static void	set_start_end(int *start, int *end, int index, int *flag)
{
	if (*flag == 1)
		*start = index;
	else if (*flag == 2)
		*end = index;
	*flag = 0;
}

static int	add_new_room(t_rooms *rooms, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	ft_error(split == NULL || split[0] == NULL || split[0][0] == 'L');
	ft_error(!split[1] || !split[2] || split[3]);
	free(line);
	ft_lstadd(&(rooms->room_name_list), ft_lstnew(split[0],\
		ft_strlen(split[0]) + 1));
	free_split(split);
	rooms->num_of_rooms++;
	return (rooms->num_of_rooms - 1);
}

void		create_rooms(t_rooms **rooms, int *start, int *end)
{
	char	*line;
	int		flag;

	*rooms = init_rooms();
	flag = 0;
	while (1)
	{
		ft_one_by_one(&line);
		if (ft_strchr(line, '-') != NULL)
		{
			add_links(rooms, line, start, end);
			break ;
		}
		if (ft_strequ("##start", line))
			flag = free_return(line, 1);
		else if (ft_strequ("##end", line))
			flag = free_return(line, 2);
		else
			set_start_end(start, end, add_new_room(*rooms, line), &flag);
	}
}
