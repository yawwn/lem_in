/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_add_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:59:33 by mcathery          #+#    #+#             */
/*   Updated: 2020/08/19 22:14:19 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lem_in.h"

int			free_return(char *line, int i)
{
	free(line);
	return (i);
}

int			ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else
		return (0);
}

void		ft_error(int i)
{
	if (i)
	{
		write(2, "Error!\n", 7);
		exit(1);
	}
}

int			ft_lemin_atoi(char *str)
{
	long	n;
	int		flag;
	int		i;

	n = 0;
	flag = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_error(1);
	if (flag == -1)
		n *= -1;
	return (n);
}

void		ft_one_by_one(char **line)
{
	char	*l;

	while (1)
	{
		get_next_line(0, &l);
		if (l[0] != '#' || ft_strequ("##start", l) || ft_strequ("##end", l))
		{
			*line = l;
			ft_printf("%s\n", l);
			break ;
		}
		else if (l[0] == '#')
			ft_printf("%s\n", l);
		free(l);
	}
}
