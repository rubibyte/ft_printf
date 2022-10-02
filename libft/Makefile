# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 20:52:25 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/02 21:23:30 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

BONUS = .bonus

OBJ_DIR = objects



SRC = ft_bzero.c		ft_isalpha.c	ft_isprint.c 	ft_memcpy.c \
	  ft_strchr.c		ft_strlcpy.c 	ft_strnstr.c 	ft_toupper.c \
	  ft_calloc.c 		ft_isascii.c	ft_memchr.c 	ft_memmove.c \
	  ft_strdup.c 		ft_strlen.c  	ft_strrchr.c	ft_atoi.c \
	  ft_isalnum.c 		ft_isdigit.c 	ft_memcmp.c 	ft_memset.c \
	  ft_strlcat.c 		ft_strncmp.c 	ft_tolower.c 	ft_substr.c \
	  ft_putchar_fd.c	ft_putstr_fd.c 	ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_striteri.c		ft_strmapi.c 	ft_itoa.c 		ft_strjoin.c \
	  ft_strtrim.c		ft_split.c

SRC_BONUS = ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c \
			ft_lstlast.c		ft_lstadd_back.c 	ft_lstdelone.c \
			ft_lstclear.c		ft_lstiter.c		ft_lstmap.c



OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRC_BONUS:.c=.o))



DEPS = $(addsuffix .d, $(basename $(OBJS)))

DEPS_BONUS = $(addsuffix .d, $(basename $(OBJS_BONUS)))



RM = rm -rf

INCLUDE = -I ./

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MMD -MP



$(OBJ_DIR)/%.o: %.c Makefile
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@



all: $(NAME)


$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "-> Objects and dependencies created."
	@echo "-> Library created."

-include $(DEPS)



$(OBJS): | $(OBJ_DIR)



$(OBJ_DIR):
	@mkdir $@
	@echo "-> Objects directory created."



$(BONUS): $(OBJS) $(OBJS_BONUS)
	@touch $@
	@ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "-> Objects and dependencies created."
	@echo "-> Library with bonus created."

-include $(DEPS_BONUS)



bonus: $(BONUS)



clean:
	@$(RM) $(OBJ_DIR)
	@echo "-> Objects directory deleted successfully."



fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "-> All files cleaned!"



re: fclean all


.PHONY: all bonus clean fclean re bonus
