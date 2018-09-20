# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azavrazh <azavrazh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 19:38:02 by azavrazh          #+#    #+#              #
#    Updated: 2018/09/18 18:33:16 by azavrazh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out

SRC_D := src/
LIBFT_D := ft_printf/
LIBFT := $(LIBFT_D)libftprintf.a
INC_D := header/
OBJ_D := .obj/

CC := clang
CFLAGS := -g #-Wall -Wextra -Werror
IFLAGS := -I $(INC_D)

SRC := lemin read connections
HFILES := $(INC_D)lemin.h

SRCS := $(addprefix $(SRC_D), $(addsuffix .c, $(SRC)))
OBJS := $(addprefix $(OBJ_D), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_D) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
$(LIBFT):
	make -C $(LIBFT_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)$(SRC_D)
$(OBJ_D)%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@ 


clean: mclean
	make clean -C $(LIBFT_D)
fclean: mfclean
	make fclean -C $(LIBFT_D)
re: fclean all

mclean:
	rm -rf $(OBJ_D)
	rm -rf $(VIS_D)$(OBJ_D)
mfclean: mclean
	rm -f $(NAME)
	rm -f $(VIS)
	rm -f $(VIS_D)$(VIS)
mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
