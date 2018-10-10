/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_execute_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:37:28 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/10 16:37:29 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_loop(int count, char ch)
{
	int		len;

	if (count < 0)
		return (0);
	len = 0;
	while (count)
	{
		write(1, &ch, 1);
		len++;
		count--;
	}
	return (len);
}

int			ft_strwrite(char *str, int count)
{
	int		i;

	i = 0;
	while (str[i] && count > 0)
	{
		write(1, &str[i], 1);
		count--;
		i++;
	}
	return (i);
}

int			s_minus_2(char *str, t_opt *flags)
{
	int		len;
	char	ch;
	int		tmp;

	ch = flags->zero ? '0' : ' ';
	len = ft_strlen(str);
	tmp = flags->precision < len ? flags->precision : len;
	if (flags->minus)
	{
		len = ft_strwrite(str, flags->precision);
		len += ft_loop(flags->width - tmp, ' ');
	}
	else
	{
		len = ft_loop(flags->width - tmp, ch);
		len += ft_strwrite(str, flags->precision);
	}
	return (len);
}

int			s_minus(char *str, t_opt *flags)
{
	int		len;
	int		tmp;
	int		ch;

	ch = flags->zero ? '0' : ' ';
	len = ft_strlen(str);
	tmp = len < flags->width ? len : flags->width;
	if (flags->minus)
	{
		len = write(1, str, tmp);
		len += ft_loop(flags->width - tmp, ' ');
	}
	else
	{
		len = ft_loop(flags->width - tmp, ch);
		len += write(1, str, tmp);
	}
	return (len);
}
