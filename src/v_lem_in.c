/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_lem_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:59:26 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/19 20:32:18 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

static int	count_ants(void)
{
	char	*line;
	int		res;

	ft_one_by_one(&line);
	res = ft_lemin_atoi(line);
	free(line);
	ft_error(res <= 0);
	return (res);
}

int			main(void)
{
	t_rooms	*rooms;
	int		num_ants;
	int		start;
	int		end;

	num_ants = count_ants();
	rooms = NULL;
	start = -1;
	end = -1;
	create_rooms(&rooms, &start, &end);
	print_ants(num_ants, start, end, rooms);
	free_rooms(rooms);
	return (0);
}
