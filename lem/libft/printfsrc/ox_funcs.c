/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:45:42 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/24 20:45:47 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			x_check_zero(t_opt *flags, char *str)
{
	if (!ft_strcmp(str, "0"))
	{
		if (flags->point && !flags->precision
			&& (!flags->sharp || flags->sp_type != 'O'))
			return (1);
	}
	return (0);
}

intmax_t	x_did_0(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			ox;

	len = ft_strlen(str);
	ox = ox_did(flags, nb, str);
	ft_putstr(str);
	free(str);
	return (len + ox);
}

int			if_ox_did(t_opt *flags, intmax_t nb, char *str)
{
	if (flags->sp_type == 'o' && flags->sharp && nb != 0)
		return (1);
	if (flags->sp_type == 'x' && flags->sharp && ft_strcmp(str, "0"))
		return (2);
	if (flags->sp_type == 'X' && flags->sharp && ft_strcmp(str, "0"))
		return (2);
	if (flags->sp_type == 'p')
		return (2);
	return (0);
}

intmax_t	x_did_2_help(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ox;

	ox = 0;
	len = ft_strlen(str);
	if (flags->zero)
	{
		ox = ox_did(flags, nb, str);
		i = ft_loop(flags->width - len, '0');
		ft_putstr(str);
	}
	else
	{
		if (if_ox_did(flags, nb, str))
			flags->width -= if_ox_did(flags, nb, str);
		i = ft_loop(flags->width - len, ' ');
		ox = ox_did(flags, nb, str);
		ft_putstr(str);
	}
	return (i + len + ox);
}

intmax_t	x_did_1_help(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			ox;

	ox = 0;
	len = ft_strlen(str);
	if ((flags->sharp && ft_strcmp(str, "0")) || flags->sp_type == 'p')
		ox = ox_did(flags, ft_atoi(str), str);
	ft_putstr(str);
	i = ft_loop(flags->width - len, ' ');
	return (i + len + ox);
}
