# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/25 22:02:25 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = libft

OBJ_DIR = .obj

DEP_DIR = .dep

#colors
#N = no color text reset
#G = green
#R = red
N = \033[0m
G = \033[0;32m
R = \033[0;31m

SRC = ft_adresstoa_base.c		ft_nbrlen_base.c		ft_printf.c	\
	  ft_printf_int.c			ft_printf_str.c 		ft_printf_unint_base.c \
	  ft_printf_void_ptr_hex.c  ft_uitoa_base.c 


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -I./ -Ilibft/include/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: ./%.c $(MAKEFILE)
	mkdir -p $(dir $@) $(DEP_DIR)/
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	mv $(patsubst %.o, %.d, $@) $(DEP_DIR)/


all:
#$(MAKE) -C $(LIBFT_DIR)
#cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(MAKE) $(NAME)


$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)


clean:
	$(MAKE) clean -C libft/
	$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)


fclean:
	$(MAKE) fclean -C libft/
	$(MAKE) clean
	$(RM) $(NAME)


re: 
	$(MAKE) fclean 
	$(MAKE) all


-include $(DEP)

.PHONY: all clean fclean re
