/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:46:09 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/03 13:46:12 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libftsrc/get_next_line.h"
# include <stddef.h>
# include <locale.h>
# include <wchar.h>

typedef struct	s_opt
{
	int			minus;
	int			plus;
	int			space;
	int			sharp;
	int			zero;
	int			precision;
	int			width;
	int			point;
	char		*modif;
	char		sp_type;
	char		rubsh;
}				t_opt;

int				ft_printf(const char *format, ...);
int				checking(char *str);
char			*search_for_flags(char *s, t_opt *flags);
int				parser(va_list ap, char *str);
void			set_all_zero(t_opt *flags);
void			put_flags(char c, t_opt *flags);
char			*put_precision(char *c, t_opt *flags);
char			*put_width(char *c, t_opt *flags);
int				put_modificator(char c, char s, t_opt *flags);
int				executor(t_opt *flags, va_list ap);
int				did_executor(t_opt *flags, va_list ap);
char			*search_helper(char *s, t_opt *flags);
intmax_t		take_arg_d(t_opt *flags, va_list ap);
void			d_precision(char *str, t_opt *flags);
void			d_width(char *str, t_opt *flags, char ch);
char			*ft_strinst(char *str);
void			d_plus(char *str, char ch);
void			minus_prec(char *str);
int				s_executor(t_opt *flags, va_list ap);
void			s_precision(int prec, char *str);
int				c_execute(t_opt *flags, va_list ap);
int				s_minus(char *str, t_opt *flags);
int				ft_loop(int count, char ch);
int				ft_strwrite(char *str, int count);
int				s_minus_2(char *str, t_opt *flags);
int				s_executor_2(char *str, t_opt *flags);
int				s_executor_3(char *str, t_opt *flags);
intmax_t		did_1(t_opt *flags, intmax_t nb);
intmax_t		did_2(t_opt *flags, intmax_t nb);
intmax_t		did_3(t_opt *flags, intmax_t nb);
intmax_t		helper_did_2(t_opt *flags, intmax_t nb);
intmax_t		helper_did(t_opt *flags, intmax_t nb);
int				percent_executor(t_opt *flags);
intmax_t		did_0(t_opt *flags, intmax_t nb);
int				ft_check_sign(t_opt *flags, intmax_t nb);
int				if_check_sign(t_opt *flags, intmax_t nb);
intmax_t		did_1_help(t_opt *flags, intmax_t nb);
intmax_t		did_1_help(t_opt *flags, intmax_t nb);
int				ft_crutch(t_opt *flags);
int				check_zero(t_opt *flags, intmax_t nb);
uintmax_t		take_arg_u(t_opt *flags, va_list ap);
int				u_executor(t_opt *flags, va_list ap);
int				bu_executor(t_opt *flags, va_list ap);
int				o_executor(t_opt *flags, va_list ap);
uintmax_t		take_arg_o(t_opt *flags, va_list ap);
int				ox_did(t_opt *flags, intmax_t nb, char *str);
char			*take_arg_x(t_opt *flags, va_list ap);
int				x_executor(t_opt *flags, va_list ap);
int				x_check_zero(t_opt *flags, char *str);
int				x_check_zero(t_opt *flags, char *str);
intmax_t		x_did_0(t_opt *flags, char *str, intmax_t nb);
intmax_t		x_did_2_help(t_opt *flags, char *str, intmax_t nb);
intmax_t		x_did_1_help(t_opt *flags, char *str);
intmax_t		x_did_1(t_opt *flags, char *str, intmax_t nb);
intmax_t		x_did_2(t_opt *flags, char *str);
intmax_t		x_helper_did(t_opt *flags, char *str);
intmax_t		x_helper_did_2(t_opt *flags, char *str);
intmax_t		x_did_3(t_opt *flags, char *str);
int				p_executor(t_opt *flags, va_list ap);
int				bc_execute(va_list ap);
int				count_bytes(wchar_t c);
int				put_wchar(wchar_t c);
int				ft_unistrwrite(wchar_t *str, int count);
int				bs_executor_3(wchar_t *str, t_opt *flags);
int				bs_executor_2(wchar_t *str, t_opt *flags);
int				bs_executor(t_opt *flags, va_list ap);
int				bs_minus_2(wchar_t *str, t_opt *flags);
int				bs_minus(wchar_t *str, t_opt *flags);
int				executor_2(t_opt *flags, va_list ap);
int				bd_executor(t_opt *flags, va_list ap);
int				bo_executor(t_opt *flags, va_list ap);
void			show_structure(t_opt *flags);
int				if_ox_did(t_opt *flags, intmax_t nb, char *str);
int				any_type(t_opt *flags);
intmax_t		a_did_2_help(t_opt *flags);
int				ft_catch_exept(t_opt *flags);
int				if_catch_exept(t_opt *flags);
int				no_spec(char c, t_opt *flags);
int				if_unistrwrite(wchar_t *str, int count);
int				big_check(t_opt *flags, int nb);
#endif
