/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:46:26 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/03 13:46:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*search_helper(char *s, t_opt *flags)
{
	while (*s)
	{
		if (*s == '.' || *(s + 1) == '.')
			flags->point = 1;
		if (*s >= '1' && *s <= '9')
			s = put_width(s, flags);
		if (*s == '.')
			s = put_precision(s + 1, flags);
		if (!(*(s + 1) >= '1' && *(s + 1) <= '9'))
			return (s);
		s++;
	}
	return (s);
}

char	*search_for_flags(char *s, t_opt *flags)
{
	while (*s)
	{
		if (*s == '.' || (*s >= '1' && *s <= '9'))
			s = search_helper(s, flags);
		if (*s == ' ' || *s == '-' || *s == '+' || *s == '#' || *s == '0')
			put_flags(*s, flags);
		else if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
			(put_modificator(*s, *(s + 1), flags) ? s++ : 0);
		else if (*s == 's' || *s == 'S' || *s == 'p' || *s == 'd' || *s == 'D'
			|| *s == 'i' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U'
			|| *s == 'x' || *s == 'X' || *s == 'c' || *s == 'C' || *s == '%')
		{
			flags->sp_type = *s;
			return (s);
		}
		else
		{
			flags->rubsh = *s;
			return (s);
		}
		s++;
	}
	return (s);
}

int		parser(va_list ap, char *str)
{
	t_opt	flags;
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			set_all_zero(&flags);
			str = search_for_flags(str + 1, &flags);
			i += executor(&flags, ap);
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	if (format)
	{
		if (checking((char *)format))
			return (ft_strlen(format));
		else if (!ft_strcmp(format, "%"))
			return (0);
		else
		{
			va_start(ap, format);
			res = parser(ap, (char *)format);
			va_end(ap);
		}
	}
	return (res);
}
