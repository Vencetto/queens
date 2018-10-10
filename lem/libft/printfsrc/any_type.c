/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:40:13 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/25 15:40:14 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			no_spec(char c, t_opt *flags)
{
	int		len;
	char	ch;

	len = 1;
	ch = flags->zero ? '0' : ' ';
	if (flags->width)
	{
		if (flags->minus)
		{
			write(1, &c, 1);
			ft_loop(flags->width - 1, ch);
			return (flags->width);
		}
		else
			len += ft_loop(flags->width - 1, ch);
	}
	write(1, &c, 1);
	return (len);
}

intmax_t	a_did_2_help(t_opt *flags)
{
	int		i;

	if (flags->zero)
		i = ft_loop(flags->width, '0');
	else
		i = ft_loop(flags->width, ' ');
	return (i);
}

int			any_type(t_opt *flags)
{
	int len;

	len = 0;
	if (flags->sp_type == '0')
		return ((len = no_spec(flags->rubsh, flags)));
	if (flags->width)
		return ((len = a_did_2_help(flags)));
	return (len);
}
