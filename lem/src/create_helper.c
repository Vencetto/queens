/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:02:16 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/20 19:02:17 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*find_room(char *str, t_all *tool)
{
	t_room		*temp;

	temp = tool->rooms;
	while (temp)
	{
		if (ft_strcmp(temp->name, str) == 0)
			return (temp);
		temp = temp->next;
	}
	just_exit("THERE IS NO ROOM LIKE THIS");
	return (NULL);
}

void			check_repeat(char *str, t_adjlist *list)
{
	t_adjlist	*temp;

	temp = list;
	while (temp)
	{
		if (ft_strcmp(str, temp->room->name) == 0)
			just_exit("LINK REPEATS");
		temp = temp->next;
	}
}

void			add_to_list(char *str, t_all *tool, int k)
{
	t_adjlist	*pos;
	t_adjlist	*new;

	check_repeat(str, tool->al[k]);
	pos = tool->al[k]->next;
	VCHECK((new = (t_adjlist*)ft_memalloc(sizeof(t_adjlist))));
	ft_bzero(new, sizeof(t_adjlist));
	new->room = find_room(str, tool);
	tool->al[k]->next = new;
	new->next = pos;
}

void			make_new(char *str, t_all *tool, int k)
{
	t_adjlist	*new;

	VCHECK((new = (t_adjlist*)ft_memalloc(sizeof(t_adjlist))));
	new->next = NULL;
	new->room = find_room(str, tool);
	tool->al[k] = new;
}
