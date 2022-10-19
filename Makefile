# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/18 21:52:35 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = libft


OBJ_DIR = obj

SRC = ft_adresstoa_base.c	ft_nbrlen_base.c	ft_printf_int.c	\
	  ft_printf_unint_base.c	ft_nbrlen.c  ft_printf.c	\
	  ft_printf_str.c	ft_printf_void_ptr_hex.c	ft_uitoa_base.c 


OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS = $(addsufix .d, basename $(OBJ))


MAKEFILE = Makefile

RM = rm -f

RM_DIR = rm -rf

INCLUDE = -I./ -Ilibft/includes/

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MMD -MP



$(OBJ_DIR)/%.o: %.c $(MAKEFILE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

-include $(DEPS)

$(OBJ_DIR):
	mkdir $@

clean:
	$(MAKE) clean -C libft/
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft/
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
