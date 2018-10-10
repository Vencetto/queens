/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:55:50 by vzomber           #+#    #+#             */
/*   Updated: 2018/09/10 14:55:52 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define START 1
# define CASUAL 0
# define END 2
# define SPACE 32

# define CHECK(x) if (!x) return (-1)
# define VCHECK(x) if (!x) return

typedef	struct			s_room
{
	char				*name;
	int					type;
	int					id;
	int					step;
	int					coord_x;
	int					coord_y;
	int					visited;
	struct s_room		*next;
}						t_room;

typedef	struct			s_que
{
	t_room				*room;
	struct s_que		*next;
}						t_que;

typedef	struct			s_adjlist
{
	t_room				*room;
	struct s_adjlist	*next;
}						t_adjlist;

typedef	struct			s_info
{
	char				*str;
	struct s_info		*next;
}						t_info;

typedef	struct			s_ant
{
	int					numb;
	t_adjlist			*way;
	struct s_ant		*next;
}						t_ant;

typedef	struct			s_all
{
	t_room				*rooms;
	t_room				*start;
	t_room				*end;

	t_que				*q_start;
	t_que				*q_end;
	size_t				q_size;

	t_adjlist			**al;

	int					ants;
	t_ant				*l_ants;

	t_adjlist			**ways;
	int					way_len;
	int					qt_ways;
	int					real_ways;
	t_info				*info;
}						t_all;

void					check_for_ants(t_all *tool, int fd);
void					parse(t_all *tool, int fd);
void					check_for_rooms(t_all *tool, int fd, int id);
int						correct_room(char *str);
int						room_type(char *line);
void					create_room(int	type, char *line, t_all *tool, int id);
void					fill_room(char *line, t_room *room, t_all *tool);
int						correct_link(char *line, t_all *tool);
void					check_links(char *line, t_all *tool, int fd, int id);
void					create_link(char *line, t_all *tool);
void					just_exit(char *str);
int						check_all_names(t_all *tool, char *line);
int						check_all_coords(t_all *tool, char *str, char *str2);
void					check_start_end(t_all *tool);
void					add_to_list(char *line, t_all *tool, int k);
void					make_new(char *str, t_all *tool, int k);
void					algo(t_all *tool);
void					ft_bfs(t_all *tool);
t_room					*find_room(char *str, t_all *tool);
void					init_adjlist(t_all *tool, int size);
t_room					*dequeue(t_all *tool, t_room *room);
void					enqueue(t_all *tool, t_adjlist *al, int step);
void					init_queue(t_que *queue, t_all *tool);
t_adjlist				*get_all_links(t_room *currentvertex, t_all *tool);
int						is_in_arr(char *str, t_all *tool);
int						find_free_space(t_adjlist **al);
int						find_way(t_all *tool, int i);
void					count_ways(t_all *tool);
void					print_rooms(t_all *tool);
int						check_exist(char *line, t_all *tool);
void					show_ways(t_all *tool);
void					go_ants(t_all *tool);
void					make_ant(t_all *tool, int i);
void					make_ants(int ants, t_all *tool);
void					write_info(t_all *tool, char *str);
void					show_info(t_all *tool);
int						is_in_way(t_room *room, t_adjlist *way);
void					delete_it(t_room *room, t_all *tool, int num);
void					real_ways(t_all *tool);
void					print_al(t_all *tool);
void					flags(char **av, t_all *tool);
int						сheck_best_way(t_all *tool, int *i);
#endif
