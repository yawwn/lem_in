/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:10:44 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/19 14:15:57 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
	}
}