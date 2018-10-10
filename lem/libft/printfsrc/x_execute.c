/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_executor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:25:50 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/21 13:25:51 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*take_arg_x(t_opt *flags, va_list ap)
{
	uintmax_t	nb;
	char		*str;

	nb = 0;
	if (!ft_strcmp(flags->modif, "h"))
		nb = (unsigned short)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "hh"))
		nb = (unsigned char)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "l"))
		nb = (unsigned long)va_arg(ap, long);
	else if (!ft_strcmp(flags->modif, "ll"))
		nb = (unsigned long long)va_arg(ap, long long);
	else if (!ft_strcmp(flags->modif, "z"))
		nb = va_arg(ap, size_t);
	else if (!ft_strcmp(flags->modif, "j"))
		nb = (uintmax_t)va_arg(ap, uintmax_t);
	else
		nb = (unsigned int)va_arg(ap, int);
	str = ft_uitoa_base(nb, 16);
	if (flags->sp_type == 'X')
		ft_upletters(str);
	return (str);
}

int				x_executor(t_opt *flags, va_list ap)
{
	char		*str;
	int			len;

	len = 0;
	str = take_arg_x(flags, ap);
	if (x_check_zero(flags, str))
		return (ft_crutch(flags));
	if (!flags->width && !flags->precision)
		return ((len = x_did_0(flags, str, 1)));
	else if (flags->width && !flags->precision)
		return ((len = x_did_1(flags, str, 1)));
	else if (!flags->width && flags->precision)
		return ((len = x_did_2(flags, str)));
	else if (flags->width && flags->precision)
		return ((len = x_did_3(flags, str)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
