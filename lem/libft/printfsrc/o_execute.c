/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:11:09 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/19 19:11:10 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t		take_arg_o(t_opt *flags, va_list ap)
{
	uintmax_t	nb;

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
		nb = (uintmax_t)va_arg(ap, intmax_t);
	else
		nb = (unsigned int)va_arg(ap, int);
	return (nb);
}

int				o_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;
	char		*str;

	len = 0;
	nb = take_arg_o(flags, ap);
	str = ft_uitoa_base(nb, 8);
	if (check_zero(flags, nb))
		return (ft_crutch(flags));
	if (if_check_sign(flags, nb) && flags->width > flags->precision)
		flags->width--;
	if (!flags->width && !flags->precision)
		return ((len = x_did_0(flags, str, nb)));
	else if (flags->width && !flags->precision)
		return ((len = x_did_1(flags, str, nb)));
	else if (!flags->width && flags->precision)
		return ((len = x_did_2(flags, str)));
	else if (flags->width && flags->precision)
		return ((len = x_did_3(flags, str)));
	ft_putstr(str);
	return (len);
}

int				bo_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;
	char		*str;

	len = 0;
	nb = va_arg(ap, long);
	str = ft_uitoa_base(nb, 8);
	if (x_check_zero(flags, str))
		return (ft_crutch(flags));
	if (!flags->width && !flags->precision)
		return ((len = x_did_0(flags, str, nb)));
	else if (flags->width && !flags->precision)
		return ((len = x_did_1(flags, str, nb)));
	else if (!flags->width && flags->precision)
		return ((len = x_did_2(flags, str)));
	else if (flags->width && flags->precision)
		return ((len = x_did_3(flags, str)));
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}
