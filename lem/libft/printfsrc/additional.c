/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:23:17 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/15 17:23:19 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_zero(t_opt *flags, intmax_t nb)
{
	if (nb == 0)
	{
		if (flags->point && !flags->precision && !flags->sharp)
			return (1);
	}
	return (0);
}

int			ft_crutch(t_opt *flags)
{
	if (flags->sp_type == 'p')
	{
		write(1, "0x", 2);
		return (2);
	}
	if (flags->width)
	{
		ft_loop(flags->width, ' ');
		return (flags->width);
	}
	return (0);
}

int			checking(char *str)
{
	if (ft_strchr((const char *)str, '%'))
		return (0);
	else
		write(1, str, ft_strlen(str));
	return (1);
}
