/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:11:11 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/12 18:11:12 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**		FILL ROOM
**	Fills room info.
*/

void				fill_room(char *line, t_room *room, t_all *tool)
{
	int				i;
	char			**arr;

	if (!line)
		return ;
	arr = ft_strsplit(line, SPACE);
	VCHECK((room->name = (char *)ft_memalloc(sizeof(char) *
			ft_strlen(arr[0]) + 1)));
	if (!check_all_names(tool, arr[0]))
		just_exit("ERROR. ROOMS WITH SAME NAMES");
	ft_strncpy(room->name, arr[0], ft_strlen(arr[0]));
	if (!check_all_coords(tool, arr[1], arr[2]))
		just_exit("ERROR. ROOMS WITH SAME COORDS");
	room->coord_x = ft_atoi(arr[1]);
	room->coord_y = ft_atoi(arr[2]);
	i = -1;
	while (arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
}

/*
**		CREATE ROOM
**	Allocates memory for room, adds it to the list, fill with info.
*/

void				create_room(int type, char *line, t_all *tool, int id)
{
	static	t_room	*last;
	t_room			*room;

	write_info(tool, line);
	VCHECK((room = (t_room *)ft_memalloc(sizeof(t_room))));
	ft_bzero(room, sizeof(room));
	if (!tool->rooms)
	{
		last = room;
		tool->rooms = room;
	}
	else
	{
		last->next = room;
		last = room;
	}
	room->id = id;
	room->type = type;
	(type == START) ? (tool->start = room) : 0;
	(type == END) ? (tool->end = room) : 0;
	room->coord_x = -12;
	room->coord_y = -12;
	fill_room(line, room, tool);
}

int					find_free_space(t_adjlist **al)
{
	int				k;

	k = -1;
	while (al[++k])
		;
	return (k);
}

int					is_in_arr(char *str, t_all *tool)
{
	int				k;

	k = -1;
	while (tool->al[++k])
	{
		if (ft_strcmp(tool->al[k]->room->name, str) == 0)
			return (k);
	}
	return (-1);
}

void				create_link(char *line, t_all *tool)
{
	int				i;
	char			*str;
	int				k;

	i = -1;
	while (line[++i] && line[i] != '-')
		;
	str = ft_strndup(line, i);
	if ((k = is_in_arr(str, tool)) + 1)
		add_to_list(&line[i + 1], tool, k);
	else
	{
		k = find_free_space(tool->al);
		make_new(str, tool, k);
		add_to_list(&line[i + 1], tool, k);
	}
	if ((k = is_in_arr(&line[i + 1], tool)) + 1)
		add_to_list(str, tool, k);
	else
	{
		k = find_free_space(tool->al);
		make_new(&line[i + 1], tool, k);
		add_to_list(str, tool, k);
	}
	ft_strdel(&str);
}
