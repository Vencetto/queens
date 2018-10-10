/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_execute_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:52:10 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/10 14:52:12 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		if_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->sp_type != 'u')
	{
		if (flags->plus)
			return (1);
		else if (flags->space)
			return (1);
		else if (nb < 0)
			return (1);
	}
	return (0);
}

int		ft_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->sp_type != 'u' && flags->sp_type != 'U')
	{
		if (flags->plus)
		{
			if (nb < 0)
				ft_putchar('-');
			else
				ft_putchar('+');
			return (1);
		}
		else if (flags->space)
		{
			if (nb < 0)
				ft_putchar('-');
			else
				ft_putchar(' ');
			return (1);
		}
		else if (nb < 0)
		{
			ft_putchar('-');
			return (1);
		}
	}
	return (0);
}

int		big_check(t_opt *flags, int nb)
{
	if ((flags->sp_type == 'o' || flags->sp_type == 'O')
		&& flags->sharp && nb != 0 && !flags->precision)
		return (1);
	else
		return (0);
}

int		ox_did(t_opt *flags, intmax_t nb, char *str)
{
	if (big_check(flags, nb))
	{
		ft_putchar('0');
		flags->width--;
		return (1);
	}
	if (flags->sp_type == 'x' && flags->sharp && ft_strcmp(str, "0"))
	{
		ft_putstr("0x");
		flags->width -= 2;
		return (2);
	}
	if (flags->sp_type == 'X' && flags->sharp && ft_strcmp(str, "0"))
	{
		ft_putstr("0X");
		flags->width -= 2;
		return (2);
	}
	if (flags->sp_type == 'p')
	{
		ft_putstr("0x");
		flags->width -= 2;
		return (2);
	}
	return (0);
}
