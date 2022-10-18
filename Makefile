# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/17 21:04:30 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printflib.a

LIBFT = Libft/libft.a


SRC = ft_lgtoa_base.c	ft_nbrlen_base.c	ft_printf_int.c	\
	  ft_printf_unint_base.c	ft_nbrlen.c  ft_printf.c	\
	  ft_printf_str.c	ft_printf_void_ptr_hex.c	ft_uitoa_base.c 


OBJS = $(SRC:.c=.o)

DEPS = $(SRC:.c=.d)


MAKEFILE = Makefile

RM = rm -f

INCLUDE = -I ./ -I Libft/includes/

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MMD -MP



%.o: %.c $(MAKEFILE)
	$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS) $(LIBFT)

-include $(DEPS)


$(LIBFT): #depende de libft_objs que a su vez dependen de libft_srcs y libft.h
	make -C Libft/


clean:
	#make clean -C Libft/
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean: clean
	#make flcean -C Libft/
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
