/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memforarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:53:33 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/05 12:53:35 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_memforarr(char **arr, int x, int y)
{
	int i;

	arr = (char **)ft_memalloc(sizeof(char*) * (x + 1));
	i = -1;
	while (++i < x)
		arr[i] = (char*)ft_memalloc(sizeof(char) * (y + 1));
	arr[i] = NULL;
	return (arr);
}
