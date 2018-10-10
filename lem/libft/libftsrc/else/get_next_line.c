/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 16:04:17 by vzomber           #+#    #+#             */
/*   Updated: 2018/08/31 16:04:19 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_substitute(char **old, char *new)
{
	char	*tmp;

	tmp = *old;
	*old = new;
	ft_strdel(&tmp);
}

static int		ft_parse_eof(char **str, char **line, ssize_t r)
{
	if (r == 0 && str && *str)
	{
		GNL_MALLCHECK((*line = ft_strsub(*str, 0, ft_strlen(*str) + 1)));
		ft_strdel(str);
		return (1);
	}
	else if (r == 0 || !*str)
	{
		ft_strdel(line);
		return (0);
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	char			*rem;
	char			buf[BUF_SIZE + 1];
	static	char	*str = NULL;
	ssize_t			r;

	if (fd <= -1 || !line)
		return (-1);
	*line ? ft_strdel(line) : line;
	while (1)
	{
		if (str && (rem = ft_strchr(str, '\n')))
		{
			GNL_MALLCHECK((*line = ft_strsub(str, 0, rem - str)));
			r = ft_strlen(rem) - 1;
			((char *)ft_memcpy_fwd(str, rem + 1, (size_t)r))[r] = '\0';
			return (str ? str != NULL : -1);
		}
		else
		{
			if (!(r = read(fd, buf, BUF_SIZE)) || r == -1 || buf[0] == '\0')
				return (ft_parse_eof(&str, line, r));
			buf[r] = '\0';
			ft_substitute(&str, ft_concat(str, buf));
		}
	}
}
