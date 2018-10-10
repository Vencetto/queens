/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:03:49 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/31 16:03:53 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_concat(char *s1, char *s2)
{
	char	*res;

	res = NULL;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 != NULL)
			res = ft_strdup(s2);
		else if (s1 != NULL)
			res = ft_strdup(s1);
	}
	else
	{
		if ((res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
		}
	}
	return (res);
}
