/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:04:43 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/10 20:04:58 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				сheck_best_way(t_all *tool, int *i)
{
	t_adjlist	*temp;

	temp = get_all_links(tool->start, tool);
	while (temp)
	{
		if (ft_strcmp(temp->room->name, tool->end->name) == 0)
		{
			find_way(tool, *i);
			++*i;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void			print_rooms(t_all *tool)
{
	t_room		*room;

	room = tool->rooms;
	ft_printf("\n  Rooms:\n------------\n");
	while (room)
	{
		ft_printf("%s -> id: %d, step: %d, coords [%d, %d] ",
			room->name, room->id, room->step, room->coord_x,
			room->coord_y);
		if (room->type == START)
			ft_printf("-> START");
		else if (room->type == END)
			ft_printf("-> END");
		room = room->next;
		ft_printf("\n");
	}
	ft_printf("------------\n");
}

void			print_al(t_all *tool)
{
	int			i;
	t_adjlist	*temp;

	ft_printf("\n  Adjlist of links\n------------\n");
	i = 0;
	while (tool->al[i])
	{
		temp = tool->al[i];
		while (temp)
		{
			ft_printf("%s -> ", temp->room->name);
			temp = temp->next;
		}
		ft_printf(" ...\n");
		i++;
	}
	ft_printf("------------\n\n");
}

void			init_adjlist(t_all *tool, int size)
{
	VCHECK((tool->al = (t_adjlist **)ft_memalloc(sizeof(t_adjlist *)
			* (size + 1))));
	tool->al[size] = NULL;
}

void			just_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}
