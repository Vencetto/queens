/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:29:27 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/10 14:29:30 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		bs_minus_2(wchar_t *str, t_opt *flags)
{
	int		len;
	char	ch;
	int		posb;

	ch = flags->zero ? '0' : ' ';
	len = ft_unistrlen(str);
	posb = if_unistrwrite(str, flags->precision);
	if (flags->minus)
	{
		len = ft_unistrwrite(str, posb);
		len += ft_loop(flags->width - posb, ' ');
	}
	else
	{
		len = ft_loop(flags->width - posb, ch);
		len += ft_unistrwrite(str, posb);
	}
	return (len);
}

int		bs_minus(wchar_t *str, t_opt *flags)
{
	int		len;
	char	ch;

	ch = flags->zero ? '0' : ' ';
	len = 0;
	if (flags->minus)
	{
		ft_putunistr(str);
		len = ft_unistrlen(str);
		len += ft_loop(flags->width - (int)ft_unistrlen(str), ' ');
	}
	else
	{
		len = ft_loop(flags->width - (int)ft_unistrlen(str), ch);
		ft_putunistr(str);
		len += ft_unistrlen(str);
	}
	return (len);
}
