/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:43:45 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 21:47:40 by mcathery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

void		remove_ste_connections(t_queue *paths, t_rooms *rooms,\
									int start, int end)
{
	t_list	*ta;
	t_list	*wrapper;

	if (rooms->paths[start][end])
	{
		ta = NULL;
		ft_lstadd(&ta, new_list(end));
		ft_lstadd(&ta, new_list(start));
		wrapper = (t_list *)malloc(sizeof(t_list));
		wrapper->content = ta;
		wrapper->content_size = 1;
		wrapper->next = NULL;
		rooms->paths[start][end] = 0;
		rooms->paths[end][start] = 0;
		push(paths, wrapper);
	}
}
