/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 12:15:01 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/16 12:15:02 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_empty(t_all *tool)
{
	return (tool->q_size == 0 ? 1 : 0);
}

int				in_queue(t_room *room, t_all *tool)
{
	t_que		*temp;

	temp = tool->q_start;
	while (temp)
	{
		if (ft_strcmp(temp->room->name, room->name) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void			ft_bfs(t_all *tool)
{
	t_que		*queue;
	t_room		*currentvertex;
	t_adjlist	*tmp;

	queue = NULL;
	init_queue(queue, tool);
	while (!is_empty(tool))
	{
		currentvertex = dequeue(tool, currentvertex);
		tmp = get_all_links(currentvertex, tool);
		while (tmp)
		{
			if (tmp->room->visited == 0 && !in_queue(tmp->room, tool))
				enqueue(tool, tmp, currentvertex->step + 1);
			tmp = tmp->next;
		}
	}
}

void			count_ways(t_all *tool)
{
	t_adjlist	*temp;
	t_adjlist	*temp2;

	temp = get_all_links(tool->start, tool);
	temp2 = get_all_links(tool->end, tool);
	tool->qt_ways = 0;
	while (temp && temp2)
	{
		tool->qt_ways++;
		temp = temp->next;
		temp2 = temp2->next;
	}
}

void			algo(t_all *tool)
{
	int			i;
	int			ret;

	ft_bfs(tool);
	count_ways(tool);
	VCHECK((tool->ways = (t_adjlist **)ft_memalloc(sizeof(t_adjlist *)
		* (tool->qt_ways + 1))));
	i = -1;
	ret = 1;
	while (++i < tool->qt_ways && ret)
	{
		if (сheck_best_way(tool, &i))
			break ;
		ret = find_way(tool, i);
		tool->start->visited = 1;
		tool->end->visited = 1;
	}
	tool->ways[i] = NULL;
}
