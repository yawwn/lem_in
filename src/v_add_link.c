/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:29:45 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/19 21:31:25 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int			get_index(char *name, t_rooms *rooms)
{
	int		i;
	char	**names;

	i = 0;
	names = rooms->room_names;
	while (names[i])
	{
		if (ft_strequ(names[i], name))
			return (i);
		i++;
	}
	ft_error(1);
	return (-1);
}

void		free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void		add_link_to_list(t_rooms **rooms, char *line)
{
	char	**split;
	int		first;
	int		second;

	split = ft_strsplit(line, '-');
	free(line);
	ft_error(!split[1] || split[2]);
	first = get_index(split[0], *rooms);
	second = get_index(split[1], *rooms);
	(*rooms)->paths[first][second] = 1;
	(*rooms)->paths[second][first] = 1;
	free_split(split);
}
