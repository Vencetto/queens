/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:19:04 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/30 18:19:05 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				real_ways(t_all *tool)
{
	int				i;

	i = -1;
	while (tool->ways[++i])
		tool->real_ways++;
}

void				make_ant(t_all *tool, int number)
{
	t_ant			*new;
	static	t_ant	*last;

	VCHECK((new = (t_ant *)ft_memalloc(sizeof(t_ant))));
	ft_bzero(new, sizeof(t_adjlist));
	if (!tool->l_ants)
	{
		last = new;
		tool->l_ants = new;
		last->next = NULL;
	}
	else
	{
		last->next = new;
		last = new;
		last->next = NULL;
	}
	new->numb = number;
	new->way = NULL;
}

void				make_ants(int ants, t_all *tool)
{
	int				i;
	t_adjlist		*temp;

	i = -1;
	while (++i < ants)
		make_ant(tool, i + 1);
	temp = tool->ways[0];
	tool->way_len = 0;
	while (temp)
	{
		tool->way_len++;
		temp = temp->next;
	}
}
