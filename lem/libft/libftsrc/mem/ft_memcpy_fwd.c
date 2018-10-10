/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_fwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:03:32 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/31 16:03:35 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_memcpy_fwd(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	unsigned const char	*sp;
	size_t				i;

	dp = (unsigned char *)dst;
	sp = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dst);
}
