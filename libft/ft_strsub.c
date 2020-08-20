/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:50:36 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 14:15:57 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	tr = ft_strnew(len);
	if (tr == NULL)
		return (NULL);
	i = (size_t)start;
	while (s[i] && i - start < len)
	{
		tr[i - start] = s[i];
		i++;
	}
	tr[i - start] = '\0';
	return (tr);
}
