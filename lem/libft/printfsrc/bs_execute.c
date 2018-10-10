/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:41:38 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/24 14:41:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		if_unistrwrite(wchar_t *str, int count)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (str[i] && count > 0)
	{
		tmp = count_bytes(str[i]);
		if ((count - tmp) >= 0)
		{
			len += count_bytes(str[i]);
			count -= tmp;
		}
		else
			return (len);
		i++;
	}
	return (len);
}

int		ft_unistrwrite(wchar_t *str, int count)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (str[i] && count > 0)
	{
		tmp = count_bytes(str[i]);
		if ((count - tmp) >= 0)
		{
			len += put_wchar(str[i]);
			count -= tmp;
		}
		i++;
	}
	return (len);
}

int		bs_executor_3(wchar_t *str, t_opt *flags)
{
	int	len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_unistrlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (flags->precision && flags->width)
	{
		if (flags->width > tmp)
			return ((len += bs_minus_2(str, flags)));
		len = ft_unistrwrite(str, flags->precision);
		return (len);
	}
	else
		ft_putunistr(str);
	return (ft_unistrlen(str));
}

int		bs_executor_2(wchar_t *str, t_opt *flags)
{
	int len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_unistrlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (if_catch_exept(flags))
		return ((len = ft_catch_exept(flags)));
	if (flags->width && !flags->precision)
	{
		if (flags->width > tmp)
			return ((len = bs_minus(str, flags)));
		len = ft_putunistr(str);
		return (len);
	}
	else if (flags->precision && !flags->width)
	{
		len = ft_unistrwrite(str, flags->precision);
		return (len);
	}
	len = bs_executor_3(str, flags);
	return (len);
}

int		bs_executor(t_opt *flags, va_list ap)
{
	int		len;
	wchar_t	*str;
	char	ch;

	len = 0;
	ch = flags->zero ? '0' : ' ';
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (ft_unistrlen(str) == 0)
	{
		if (flags->width)
			len = ft_loop(flags->width, ' ');
		return (len);
	}
	len = bs_executor_2(str, flags);
	return (len);
}
