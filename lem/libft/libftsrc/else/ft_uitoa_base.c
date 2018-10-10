/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:56:23 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/21 16:56:25 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_uitoa_base(uintmax_t nb, int base)
{
	int		len;
	char	*str;
	int		sign;

	sign = 0;
	len = ft_ulen(nb, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb /= base;
	}
	return (str);
}
