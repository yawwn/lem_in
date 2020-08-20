/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:25:11 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 19:45:28 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

t_queue	*new_t_queue(void)
{
	t_queue	*tr;

	tr = (t_queue *)malloc(sizeof(t_queue));
	tr->first = NULL;
	tr->last = NULL;
	return (tr);
}

int		is_empty(t_queue *queue)
{
	return (queue->first == NULL);
}

void	push(t_queue *queue, t_list *ta)
{
	ta->next = NULL;
	if (is_empty(queue))
	{
		queue->first = ta;
		queue->last = ta;
	}
	else
	{
		queue->last->next = ta;
		queue->last = ta;
	}
}

t_list	*pop(t_queue *queue)
{
	t_list	*tr;

	if (is_empty(queue))
		return (NULL);
	tr = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	return (tr);
}

t_list	*peek(t_queue *queue)
{
	return (queue->first);
}
