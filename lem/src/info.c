/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:02:47 by vzomber           #+#    #+#             */
/*   Updated: 2018/10/01 18:02:48 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				write_info(t_all *tool, char *str)
{
	static	t_info	*last;
	t_info			*info;

	VCHECK((info = (t_info *)ft_memalloc(sizeof(t_info))));
	VCHECK((info->str = (char *)ft_memalloc(sizeof(char) *
		(ft_strlen(str) + 1))));
	ft_strcpy(info->str, str);
	if (!tool->info)
	{
		last = info;
		tool->info = info;
	}
	else
	{
		last->next = info;
		last = info;
	}
}

void				show_info(t_all *tool)
{
	t_info			*temp;

	temp = tool->info;
	while (temp)
	{
		ft_printf("%s\n", temp->str);
		temp = temp->next;
	}
	ft_printf("\n");
}

void				show_ways(t_all *tool)
{
	int				i;
	t_adjlist		*temp;

	i = -1;
	ft_printf("\n  Ways:\n------------\n");
	while (tool->ways[++i])
	{
		temp = tool->ways[i];
		while (temp)
		{
			ft_printf("%s ", temp->room->name);
			temp = temp->next;
		}
		ft_printf("-> ...\n");
	}
	ft_printf("------------\n\n");
}
