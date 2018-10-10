/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_execute_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:52:21 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/10 14:52:22 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		helper_did(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (flags->zero)
	{
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (len + tmp), ' ');
		ch = ft_check_sign(flags, nb);
		i += ft_loop(tmp, '0') + len;
		ft_putnbr_m(nb);
	}
	else
	{
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (len + tmp), ' ');
		ch = ft_check_sign(flags, nb);
		i += ft_loop(tmp, '0') + len;
		ft_putnbr_m(nb);
	}
	return (i + ch);
}

intmax_t		helper_did_2(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	ch = ft_check_sign(flags, nb);
	i = ft_loop(tmp, '0') + len;
	ft_putnbr_m(nb);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	return (i + ch);
}

intmax_t		did_3(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ox;

	i = 0;
	ox = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (flags->width >= (tmp + len) || flags->precision > flags->width)
	{
		if (flags->minus)
			i = helper_did_2(flags, nb);
		else
			i = helper_did(flags, nb);
		return (i);
	}
	ox += if_check_sign(flags, nb);
	ft_putnbr(nb);
	return (len + ox);
}

intmax_t		take_arg_d(t_opt *flags, va_list ap)
{
	intmax_t	nb;

	nb = 0;
	if (!ft_strcmp(flags->modif, "h"))
		nb = (short)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "hh"))
		nb = (signed char)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "l"))
		nb = (long)va_arg(ap, long);
	else if (!ft_strcmp(flags->modif, "ll"))
		nb = va_arg(ap, long long);
	else if (!ft_strcmp(flags->modif, "j"))
		nb = va_arg(ap, intmax_t);
	else if (!ft_strcmp(flags->modif, "z"))
		nb = (ptrdiff_t)va_arg(ap, size_t);
	else
		nb = va_arg(ap, int);
	return (nb);
}

int				bd_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;

	len = 0;
	nb = va_arg(ap, long);
	if (check_zero(flags, nb))
		return (ft_crutch(flags));
	if (if_check_sign(flags, nb) && flags->width > flags->precision)
		flags->width--;
	if (!flags->width && !flags->precision)
		return ((len = did_0(flags, nb)));
	else if (flags->width && !flags->precision)
		return ((len = did_1(flags, nb)));
	else if (!flags->width && flags->precision)
		return ((len = did_2(flags, nb)));
	else if (flags->width && flags->precision)
		return ((len = did_3(flags, nb)));
	ft_putnbr(nb);
	len = ft_len(nb, 10);
	if (nb < 0)
		len++;
	return (len);
}
