/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 15:14:53 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/11 15:15:04 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**		CORRECT LINKS
**	Must be name, '-', name, '\n', nothing more.
*/

int				correct_link(char *line, t_all *tool)
{
	int			check;

	check = 0;
	if (!line || *line == '#')
		return (0);
	if (check_exist(line, tool))
		check++;
	if (ft_strcchr(line, '-') == 1)
		check++;
	if (!ft_strchr(line, SPACE))
		check++;
	return (check == 3 ? 1 : 0);
}

/*
**		CHECK ALL NAMES
**	Goes through list and looks for overlaps of names.
*/

int				check_all_names(t_all *tool, char *str)
{
	t_room		*tmp;

	tmp = tool->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, str) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**		CHECK ALL COORDS
**	Goes through list and looks for overlaps of coords.
*/

int				check_all_coords(t_all *tool, char *str, char *str2)
{
	t_room		*tmp;
	intmax_t	x;
	intmax_t	y;

	if (!str || !str2)
		return (0);
	x = ft_atoi(str);
	y = ft_atoi(str2);
	tmp = tool->rooms;
	while (tmp)
	{
		if (tmp->coord_x == x && tmp->coord_y == y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int				correct_room(char *str)
{
	char		**names;
	int			i;

	if (*str == 'L' || *str == '#' || ft_strcchr(str, SPACE) != 2)
		return (0);
	names = ft_strsplit(str, SPACE);
	if (ft_strisnumber(names[1])
	&& ft_strisnumber(names[2])
	&& names[3] == NULL)
	{
		i = -1;
		while (names[++i])
			ft_strdel(&names[i]);
		free(names);
		return (1);
	}
	i = -1;
	while (names[++i])
		ft_strdel(&names[i]);
	free(names);
	return (0);
}

/*
**		ROOM TYPE
**	Checking the type of room, watch header file.
*/

int				room_type(char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		return (START);
	else if (ft_strcmp(line, "##end") == 0)
		return (END);
	return (CASUAL);
}
