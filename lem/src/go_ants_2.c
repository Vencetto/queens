/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_ants_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:24:29 by vzomber           #+#    #+#             */
/*   Updated: 2018/10/01 18:24:30 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ants_in_way(t_ant *l_ants)
{
	t_ant		*temp;

	temp = l_ants;
	while (temp)
	{
		if (temp->way)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void			move_ants_once(t_ant *l_ants)
{
	t_ant		*ant;

	ant = l_ants;
	while (ant)
	{
		if (ant->way)
		{
			ft_printf("L%d-%s ", ant->numb, ant->way->room->name);
			ant->way = ant->way->next;
		}
		ant = ant->next;
	}
	ft_printf("\n");
}

void			go_ants(t_all *tool)
{
	int			i;
	t_ant		*ant;

	show_info(tool);
	ant = tool->l_ants;
	while (42)
	{
		i = -1;
		while (ant && ++i < tool->real_ways)
		{
			if (tool->ants <= tool->way_len)
			{
				ant->way = tool->ways[0]->next;
				ant = ant->next;
				break ;
			}
			else
				ant->way = tool->ways[ant->numb % tool->real_ways]->next;
			ant = ant->next;
		}
		if (ants_in_way(tool->l_ants))
			move_ants_once(tool->l_ants);
		else
			break ;
	}
}
