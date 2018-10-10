/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:01:33 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/24 12:01:45 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjlist	*get_all_links(t_room *currentvertex, t_all *tool)
{
	int		i;

	i = -1;
	while (tool->al[++i])
	{
		if (ft_strcmp(tool->al[i]->room->name, currentvertex->name) == 0)
			return (tool->al[i]->next);
	}
	return (NULL);
}

void		init_queue(t_que *queue, t_all *tool)
{
	VCHECK((queue = (t_que *)ft_memalloc(sizeof(t_que))));
	tool->start->visited = 1;
	tool->start->step = 1;
	queue->room = tool->start;
	queue->next = NULL;
	tool->q_start = queue;
	tool->q_end = queue;
	tool->q_size++;
}

void		enqueue(t_all *tool, t_adjlist *al, int step)
{
	t_que	*new;

	VCHECK((new = (t_que *)ft_memalloc(sizeof(t_que))));
	new->room = al->room;
	tool->q_end->next = new;
	tool->q_end = new;
	new->room->visited = 1;
	new->room->step = step;
	new->next = NULL;
	tool->q_size++;
}

t_room		*dequeue(t_all *tool, t_room *room)
{
	t_que	*temp;

	temp = tool->q_start;
	if (tool->q_start->room == room)
	{
		tool->q_start = tool->q_start->next;
		free(temp);
	}
	tool->q_size--;
	return (tool->q_start->room);
}
