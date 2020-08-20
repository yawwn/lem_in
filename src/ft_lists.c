/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 18:10:10 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 20:40:12 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

t_list		*new_list(int i)
{
	t_list	*tr;
	int		*hi;

	tr = (t_list *)malloc(sizeof(t_list));
	hi = (int *)malloc(sizeof(int));
	*hi = i;
	tr->content = hi;
	tr->content_size = 0;
	tr->next = NULL;
	return (tr);
}

int			ft_get_lst_size(t_list *list)
{
	t_list	*l;
	int		tr;

	l = list;
	tr = 0;
	while (l)
	{
		tr++;
		l = l->next;
	}
	return (tr);
}

t_list		**ft_lst_to_array(t_list *list, int *size)
{
	int		i;
	t_list	*l;
	t_list	**tr;

	*size = ft_get_lst_size(list);
	tr = (t_list **)malloc(sizeof(t_list *) * (*size));
	if (tr == NULL)
		return (NULL);
	l = list;
	i = 0;
	while (l)
	{
		tr[i] = l;
		i++;
		l = l->next;
	}
	return (tr);
}
