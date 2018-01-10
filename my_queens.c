/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_queens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:24:32 by vzomber           #+#    #+#             */
/*   Updated: 2018/01/10 16:27:38 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int g_iterator = 0;

int		is_safe(int rows[8], int x, int y)
{
	int i;

	i = 0;
	if (y == 0)
		return (1);
	while (i < y)
	{
		if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y + i)
			return (0);
		i++;
	}
	return (1);
}

void	master(int rows[8], int y)
{
	int x;

	x = 0;
	while (x < 8)
	{
		if (is_safe(rows, x, y))
		{
			rows[y] = x;
			if (y == 7)
				g_iterator++;
			else
				master(rows, y + 1);
		}
		x++;
	}
}

int		main(void)
{
	int rows[8];

	master(rows, 0);
	printf("%d\n", g_iterator);
	return (0);
}
