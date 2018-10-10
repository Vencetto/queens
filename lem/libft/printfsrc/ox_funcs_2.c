/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_funcs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:24:38 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/10 16:24:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		x_did_1(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ox;

	len = ft_strlen(str);
	if (flags->width > len)
	{
		if (flags->minus)
			i = x_did_1_help(flags, str);
		else
			i = x_did_2_help(flags, str, nb);
		return (i);
	}
	ox = ox_did(flags, nb, str);
	ft_putstr(str);
	free(str);
	return (len + ox);
}

intmax_t		x_did_2(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			ox;

	i = 0;
	len = ft_strlen(str);
	ox = 0;
	ox = ox_did(flags, ft_atoi(str), str);
	if (flags->precision > len)
	{
		i = ft_loop(flags->precision - len, '0') + len;
		ft_putstr(str);
		return (i + ox);
	}
	ft_putstr(str);
	free(str);
	return (len + ox);
}

intmax_t		x_helper_did(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ox;

	i = 0;
	len = ft_strlen(str);
	ox = 0;
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (if_ox_did(flags, ft_atoi(str), str))
		flags->width -= if_ox_did(flags, ft_atoi(str), str);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	ox = ox_did(flags, ft_atoi(str), str);
	i += ft_loop(tmp, '0') + len;
	ft_putstr(str);
	free(str);
	return (i + ox);
}

intmax_t		x_helper_did_2(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ox;

	i = 0;
	ox = 0;
	len = ft_strlen(str);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	ox = ox_did(flags, ft_atoi(str), str);
	i = ft_loop(tmp, '0') + len;
	ft_putstr(str);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	return (i);
}

intmax_t		x_did_3(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ox;

	i = 0;
	ox = 0;
	len = ft_strlen(str);
	tmp = flags->precision > len ? flags->precision : 0;
	if (flags->width >= tmp || flags->precision > flags->width)
	{
		if (flags->minus)
			i = x_helper_did_2(flags, str);
		else
			i = x_helper_did(flags, str);
		return (i);
	}
	ox = ox_did(flags, ft_atoi(str), str);
	ft_putstr(str);
	free(str);
	return (len + ox);
}
