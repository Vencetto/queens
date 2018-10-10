/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:54:36 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/10 14:54:37 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				is_in_way(t_room *room, t_adjlist *way)
{
	t_adjlist	*temp;

	temp = way;
	while (temp)
	{
		if (ft_strcmp(temp->room->name, room->name) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void			delete_it(t_room *room, t_all *tool, int num)
{
	t_adjlist	*temp;
	t_adjlist	*rememb;
	int			ch;

	temp = tool->ways[num];
	ch = INT_MAX;
	while (temp && --ch)
	{
		if (ft_strcmp(temp->room->name, room->name) == 0)
			ch = 2;
		rememb = temp->next;
		free(temp);
		tool->ways[num] = rememb;
		temp = rememb;
	}
}

int				check_exist(char *line, t_all *tool)
{
	t_room		*tmp;
	int			i;

	CHECK(line);
	i = 0;
	while (line[++i] && line[i] != '-')
		;
	tmp = tool->rooms;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, line, i) == 0 ||
			ft_strcmp(tmp->name, &line[i + 1]) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			flags(char **av, t_all *tool)
{
	int			i;

	i = 0;
	while (av[++i])
	{
		if (ft_strcmp(av[i], "-al") == 0)
			print_al(tool);
		if (ft_strcmp(av[i], "-r") == 0)
			print_rooms(tool);
		if (ft_strcmp(av[i], "-w") == 0)
			show_ways(tool);
	}
}

int				main(int ac, char **av)
{
	t_all		tool;

	if (ac >= 1)
	{
		if (av[1] && ft_strcmp(av[1], "-h") == 0)
		{
			ft_printf("usage: ./lem-in [file]  [-w -> shows all ways]\n\t\t"
					"	[-al -> shows list of links]\n\t\t"
					"	[-r -> shows list of rooms]\n");
			exit(1);
		}
		ft_bzero(&tool, sizeof(tool));
		parse(&tool, 0);
		algo(&tool);
		make_ants(tool.ants, &tool);
		real_ways(&tool);
		if (tool.qt_ways <= 0 || tool.real_ways <= 0)
			just_exit("ERROR. NOT ENOUGHT DATA OR NO WAY");
		go_ants(&tool);
		flags(av, &tool);
	}
	return (0);
}
