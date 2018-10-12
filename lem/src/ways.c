/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ways.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:18:13 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/25 18:18:14 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*get_min_node(t_adjlist *next, t_room *elem)
{
	int			min;

	min = INT_MAX;
	while (next && elem->type != START)
	{
		if (next->room->step < min && next->room->visited)
		{
			min = next->room->step;
			elem = next->room;
		}
		next = next->next;
	}
	elem->visited = 0;
	return (elem);
}

void			create_path(t_room *room, t_all *tool, int num)
{
	t_adjlist	*new;

	VCHECK((new = (t_adjlist*)ft_memalloc(sizeof(t_adjlist))));
	new->room = room;
	tool->ways[num] = new;
	new->next = NULL;
}

void			add_to_path(t_room *room, t_all *tool, int num)
{
	t_adjlist	*pos;
	t_adjlist	*new;

	pos = tool->ways[num];
	VCHECK((new = (t_adjlist*)ft_memalloc(sizeof(t_adjlist))));
	new->room = room;
	tool->ways[num] = new;
	new->next = pos;
}

int				break_path(t_all *tool, int num)
{
	free(tool->ways[num]);
	tool->ways[num] = NULL;
	return (0);
}

int				find_way(t_all *tool, int num)
{
	t_room		*elem;
	t_adjlist	*next;
	t_room		*check;

	elem = tool->end;
	create_path(elem, tool, num);
	while (elem && elem->type != START)
	{
		next = get_all_links(elem, tool);
		check = elem;
		elem = get_min_node(next, elem);
		if (check->name == elem->name)
			return (break_path(tool, num));
		if (is_in_way(elem, tool->ways[num]))
			delete_it(elem, tool, num);
		add_to_path(elem, tool, num);
	}
	return (1);
}
