/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:03:40 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/14 15:03:41 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		s_executor_3(char *str, t_opt *flags)
{
	int	len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_strlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (flags->precision && flags->width)
	{
		if (flags->width > tmp)
			return ((len += s_minus_2(str, flags)));
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int		if_catch_exept(t_opt *flags)
{
	if (flags->point && !flags->precision && flags->zero)
		return (1);
	if (flags->point && !flags->precision && flags->width)
		return (1);
	return (0);
}

int		ft_catch_exept(t_opt *flags)
{
	int	len;

	len = 0;
	if (flags->point && !flags->precision && flags->zero)
		return ((len = ft_loop(flags->width, '0')));
	if (flags->point && !flags->precision && flags->width)
		return ((len = ft_loop(flags->width, ' ')));
	return (len);
}

int		s_executor_2(char *str, t_opt *flags)
{
	int	len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_strlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (if_catch_exept(flags))
		return ((len = ft_catch_exept(flags)));
	if (flags->width && !flags->precision)
	{
		if (flags->width > tmp)
			return ((len = s_minus(str, flags)));
		len = ft_strwrite(str, flags->width);
		return (len);
	}
	if (flags->precision && !flags->width)
	{
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	len = s_executor_3(str, flags);
	return (len);
}

int		s_executor(t_opt *flags, va_list ap)
{
	int		len;
	char	*str;
	char	ch;

	len = 0;
	ch = flags->zero ? '0' : ' ';
	str = va_arg(ap, char *);
	if (str == NULL && !flags->width)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (ft_strlen(str) == 0)
	{
		if (flags->width)
			len = ft_loop(flags->width, ch);
		return (len);
	}
	len = s_executor_2(str, flags);
	return (len);
}
