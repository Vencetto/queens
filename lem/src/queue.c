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

void		init_queue(t_all *tool)
{
	t_que	*new;

	VCHECK((new = (t_que*)ft_memalloc(sizeof(t_que))));
	tool->start->visited = 1;
	tool->start->step = 1;
	new->room = tool->start;
	new->next = NULL;
	tool->q_start = new;
	tool->q_end = new;
	tool->q_size = 1;
}

void		enqueue(t_all *tool, t_adjlist *al, int step)
{
	t_que	*new;

	VCHECK((new = (t_que*)ft_memalloc(sizeof(t_que))));
	new->room = al->room;
	if (!tool->q_start)
		tool->q_start = new;
	if (tool->q_end)
		tool->q_end->next = new;
	tool->q_end = new;
	new->room->visited = 1;
		new->room->step = step;
	new->next = NULL;
	tool->q_size++;
}

t_room		*dequeue(t_all *tool)
{
	t_que	*temp;
	t_room	*tmp_room;

	temp = tool->q_start;
	if (temp)
	{
		tmp_room = temp->room;
		tool->q_start = tool->q_start->next;
		free(temp);
		tool->q_size--;
		if (!tool->q_start)
			tool->q_end = NULL;
		return (tmp_room);
	}
	return (NULL);
}
