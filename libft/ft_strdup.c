/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:01:06 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 14:15:57 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tr;
	size_t	i;

	tr = (char *)malloc((1 + ft_strlen(str)) * sizeof(char));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tr[i] = str[i];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
