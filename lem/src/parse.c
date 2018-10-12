/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:21:09 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/10 17:21:11 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**			CHECK_FOR_ANTS
**	Looks for ants, skipping all the rubbish.
**	If finds "##start" or "##end"
**	before number of ants, it stops. If finds rubbish
**	instead of number, also stops.
*/

void		check_for_ants(t_all *tool, int fd)
{
	char	*line;

	line = NULL;
	if (!get_next_line(fd, &line) || !line)
		just_exit("ERROR. CANNOT READ FROM LINE");
	while (ft_strstr(line, "#"))
	{
		write_info(tool, line);
		ft_strdel(&line);
		get_next_line(fd, &line);
	}
	if (!ft_strisnumber(line))
		just_exit("ERROR. MUST BE NUMBER OF ANTS");
	tool->ants = ft_atoi(line);
	write_info(tool, line);
	if (tool->ants <= 0)
		just_exit("ERROR. BAD NUMBER");
	ft_strdel(&line);
}

/*
**		CHECK LINKS
**	Reads links and checking them, skipping all the rubbish.
*/

void		check_links(char *line, t_all *tool, int fd, int id)
{
	init_adjlist(tool, id);
	while (1)
	{
		if (!line || !ft_strcmp(line, ""))
			break ;
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			just_exit("ERROR. IT SHOULDN'T BE HERE");
		if (*line == '#')
		{
			write_info(tool, line);
			ft_strdel(&line);
			get_next_line(fd, &line);
			continue ;
		}
		if (!correct_link(line, tool))
			just_exit("ERROR. INCORRECT LINK");
		else
			create_link(line, tool);
		write_info(tool, line);
		ft_strdel(&line);
		get_next_line(fd, &line);
	}
	ft_strdel(&line);
}

void		check_for_rooms(t_all *tool, int fd, int id)
{
	char	*line;
	int		type;

	line = NULL;
	type = 0;
	while (get_next_line(fd, &line) && !correct_link(line, tool))
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
			type = room_type(line);
		if (*line == '#')
		{
			write_info(tool, line);
			ft_strdel(&line);
			continue ;
		}
		if (!correct_room(line))
			just_exit("ERROR. INCORRECT ROOM");
		else
		{
			create_room(type, line, tool, ++id);
			type = 0;
		}
		ft_strdel(&line);
	}
	check_links(line, tool, fd, ++id);
}

void		check_start_end(t_all *tool)
{
	t_room	*tmp;
	int		ch_1;
	int		ch_2;

	ch_1 = 0;
	ch_2 = 0;
	tmp = tool->rooms;
	while (tmp)
	{
		if (tmp->type == START)
			ch_1++;
		if (tmp->type == END)
			ch_2++;
		tmp = tmp->next;
	}
	if (ch_1 > 1)
		just_exit("ERROR, '##START' IS TWICE");
	if (ch_2 > 1)
		just_exit("ERROR, '##END' IS TWICE");
	if (ch_1 == 0)
		just_exit("ERROR, THERE IS NO '##START'");
	if (ch_2 == 0)
		just_exit("ERROR, THERE IS NO '##END'");
}

/*
**			PARSE
**	Parsing input information.
**	Checking for correct ants, rooms, ...
*/

void		parse(t_all *tool, int fd)
{
	int		id;

	id = -1;
	check_for_ants(tool, fd);
	check_for_rooms(tool, fd, id);
	check_start_end(tool);
}
