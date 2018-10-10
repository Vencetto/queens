/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:43:31 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/30 15:43:32 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcchr(const char *s, int c)
{
	int		i;
	size_t	len;
	int		count;

	len = ft_strlen(s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if ((unsigned char)c == '\0')
			return (count);
		if (s[i] == (unsigned char)c)
			count++;
		i++;
	}
	return (count);
}
