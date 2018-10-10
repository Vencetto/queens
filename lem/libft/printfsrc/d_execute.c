/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:26:55 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/15 18:26:56 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	did_0(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			ox;

	if (flags->sp_type == 'u' || flags->sp_type == 'U')
		len = ft_ulen(nb, 10);
	else
		len = ft_len(nb, 10);
	len += ft_check_sign(flags, nb);
	ox = ox_did(flags, nb, NULL);
	if (flags->sp_type == 'u' || flags->sp_type == 'U')
		ft_uputnbr_m(nb);
	else
		ft_putnbr_m(nb);
	return (len + ox);
}

intmax_t	did_2_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;
	int			ox;

	ox = 0;
	len = ft_len(nb, 10);
	if (flags->zero)
	{
		tmp = ft_check_sign(flags, nb);
		ox = ox_did(flags, nb, NULL);
		i = ft_loop(flags->width - len, '0');
		ft_putnbr_m(nb);
	}
	else
	{
		i = ft_loop(flags->width - len, ' ');
		ox = ox_did(flags, nb, NULL);
		tmp = ft_check_sign(flags, nb);
		ft_putnbr_m(nb);
	}
	return (i + len + tmp + ox);
}

intmax_t	did_1_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;
	int			ox;

	ox = 0;
	len = ft_len(nb, 10);
	tmp = ft_check_sign(flags, nb);
	if (flags->sp_type == 'o' && flags->sharp && nb != 0)
	{
		ft_putchar('0');
		ox++;
		flags->width--;
	}
	ft_putnbr_m(nb);
	i = ft_loop(flags->width - len, ' ');
	return (i + len + tmp + ox);
}

intmax_t	did_1(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ch;

	ch = 0;
	len = ft_len(nb, 10);
	if (flags->width > len)
	{
		if (flags->minus)
			i = did_1_help(flags, nb);
		else
			i = did_2_help(flags, nb);
		return (i);
	}
	ch = ft_check_sign(flags, nb);
	ft_putnbr_m(nb);
	return (len + ch);
}

intmax_t	did_2(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	ch = ft_check_sign(flags, nb);
	if (flags->precision > len)
	{
		i = ft_loop(flags->precision - len, '0') + len;
		ft_putnbr_m(nb);
		return (i + ch);
	}
	ft_putnbr_m(nb);
	return (len + ch);
}
