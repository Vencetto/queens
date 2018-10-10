# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzomber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 18:34:19 by vzomber           #+#    #+#              #
#    Updated: 2018/03/08 18:34:20 by vzomber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCPRINTF =	printfsrc/ft_printf.c printfsrc/put_into_struct.c printfsrc/additional.c printfsrc/d_execute.c printfsrc/d_execute_2.c \
			printfsrc/d_execute_3.c printfsrc/s_execute.c printfsrc/s_execute_2.c printfsrc/executor.c printfsrc/c_execute.c \
			printfsrc/u_execute.c printfsrc/o_execute.c printfsrc/x_execute.c printfsrc/ox_funcs.c printfsrc/ox_funcs_2.c \
			printfsrc/p_execute.c printfsrc/bs_execute.c printfsrc/bs_additional.c printfsrc/any_type.c

SRCLIB =	libftsrc/else/ft_abs.c libftsrc/else/ft_atoi.c libftsrc/else/ft_bzero.c libftsrc/else/ft_chars.c libftsrc/else/ft_count_bytes.c \
			libftsrc/else/ft_huge_mzfk.c libftsrc/else/ft_isalnum.c libftsrc/else/ft_isalpha.c libftsrc/else/ft_isascii.c libftsrc/else/ft_isdigit.c \
			libftsrc/else/ft_isprint.c libftsrc/else/ft_itoa.c libftsrc/else/ft_itoa_base.c libftsrc/else/ft_len.c libftsrc/else/ft_tolower.c \
			libftsrc/else/ft_toupper.c libftsrc/else/ft_uhuge_mzfk.c libftsrc/else/ft_uitoa_base.c libftsrc/else/ft_ulen.c libftsrc/else/ft_upletters.c \
			libftsrc/else/ft_wordnum.c libftsrc/else/get_next_line.c \
			libftsrc/str/ft_concat.c libftsrc/str/ft_strcat.c libftsrc/str/ft_strchr.c libftsrc/str/ft_strclr.c libftsrc/str/ft_strcmp.c libftsrc/str/ft_strcpy.c libftsrc/str/ft_strdel.c \
			libftsrc/str/ft_strdup.c libftsrc/str/ft_strequ.c libftsrc/str/ft_striter.c libftsrc/str/ft_striteri.c libftsrc/str/ft_strjoin.c libftsrc/str/ft_strlcat.c \
			libftsrc/str/ft_strlen.c libftsrc/str/ft_strmap.c libftsrc/str/ft_strmapi.c libftsrc/str/ft_strncat.c libftsrc/str/ft_strncmp.c libftsrc/str/ft_strncpy.c \
			libftsrc/str/ft_strnequ.c libftsrc/str/ft_strnew.c libftsrc/str/ft_strnstr.c libftsrc/str/ft_strrchr.c libftsrc/str/ft_strsplit.c libftsrc/str/ft_strstr.c \
			libftsrc/str/ft_strsub.c libftsrc/str/ft_strtrim.c libftsrc/str/ft_unistrlen.c libftsrc/str/ft_strisnumber.c libftsrc/str/ft_strndup.c libftsrc/str/ft_strcchr.c\
			libftsrc/put/ft_putchar.c libftsrc/put/ft_putchar_fd.c libftsrc/put/ft_putendl.c libftsrc/put/ft_putendl_fd.c libftsrc/put/ft_putnbr.c libftsrc/put/ft_putnbr_fd.c \
			libftsrc/put/ft_putnbr_m.c libftsrc/put/ft_putstr.c libftsrc/put/ft_putstr_fd.c libftsrc/put/ft_putunistr.c libftsrc/put/ft_putwchar.c libftsrc/put/ft_uputnbr_m.c \
			libftsrc/mem/ft_memalloc.c libftsrc/mem/ft_memccpy.c libftsrc/mem/ft_memchr.c libftsrc/mem/ft_memcmp.c libftsrc/mem/ft_memcpy.c libftsrc/mem/ft_memdel.c \
			libftsrc/mem/ft_memmove.c libftsrc/mem/ft_memset.c libftsrc/mem/ft_memcpy_fwd.c libftsrc/mem/ft_memforarr.c\
			libftsrc/lst/ft_lstadd.c libftsrc/lst/ft_lstdel.c libftsrc/lst/ft_lstdelone.c libftsrc/lst/ft_lstend.c libftsrc/lst/ft_lstiter.c libftsrc/lst/ft_lstmap.c libftsrc/lst/ft_lstnew.c
 
 
OBJ = $(SRCPRINTF:.c=.o) $(SRCLIB:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m  \033[36mlibft \033[32mdone\033[0m"

%.o: %.c includes/ft_printf.h
	@gcc -c $< -o $@ $(FLAGS) -I libftsrc

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all