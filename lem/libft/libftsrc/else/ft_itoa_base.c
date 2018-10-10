/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:42:01 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/17 18:42:03 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_itoa_base(intmax_t nb, int base)
{
	int		len;
	char	*str;
	int		sign;

	sign = 0;
	len = ft_len(nb, base);
	if (nb < -9223372036854775807)
		return (ft_itoa(nb));
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb < 0 && base == 10)
	{
		len++;
		sign = 1;
		nb *= -1;
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb /= base;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
