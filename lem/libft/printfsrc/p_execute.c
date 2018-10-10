/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:43:46 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/22 13:43:47 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_executor(t_opt *flags, va_list ap)
{
	char		*str;
	int			len;
	intmax_t	nb;

	len = 0;
	nb = (uintptr_t)va_arg(ap, void *);
	str = ft_uitoa_base(nb, 16);
	if (check_zero(flags, nb))
		return (ft_crutch(flags));
	if (!flags->width && !flags->precision)
		return ((len = x_did_0(flags, str, nb)));
	else if (flags->width && !flags->precision)
		return ((len = x_did_1(flags, str, nb)));
	else if (!flags->width && flags->precision)
		return ((len = x_did_2(flags, str)));
	else if (flags->width && flags->precision)
		return ((len = x_did_3(flags, str)));
	ft_putstr("0x");
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
