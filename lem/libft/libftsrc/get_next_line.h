/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:48:06 by vzomber           #+#    #+#             */
/*   Updated: 2018/01/10 18:48:08 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>

# define GNL_BUFF_SIZE 1000
# define BUF_SIZE 1000
# define GNL_MALLCHECK(x) if (!(x)) return (-1);

typedef unsigned char		t_uc;

typedef struct		s_line
{
	t_uc			*str;
	size_t			len;
}					t_line;

typedef struct		s_fds
{
	char			*str;
	int				fd;
	struct s_fds	*next;
}					t_fds;

int					get_next_line(const int fd, char **line);
#endif
