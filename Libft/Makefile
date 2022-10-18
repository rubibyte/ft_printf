# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 20:52:25 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/18 02:14:10 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

BONUS = .bonus

SRC_DIR = sources

OBJ_DIR = objects

DEPS_DIR = dependencies


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


DEPS = $(addprefix $(DEPS_DIR)/, $(SRC:.c=.d))

DEPS_BONUS = $(addprefix $(DEPS_DIR)/, $(SRC_BONUS:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MMD -MP

INCLUDE = -I includes/

RM = rm -rf


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MAKEFILE)
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(DEPS_DIR)/

all: 
	@$(MAKE) $(NAME)


$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "-> Objects and dependencies created."
	@echo "-> Library created."

-include $(DEPS)


$(OBJS): | $(OBJ_DIR)


$(OBJ_DIR):
	@mkdir $@
	@echo "-> Objects directory created."


$(DEPS): | $(DEPS_DIR)


$(DEPS_DIR):
	@mkdir $@
	@echo "-> Dependencies directory created."


$(BONUS): $(OBJS) $(OBJS_BONUS)
	@touch $@
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)
	@echo "-> Objects and dependencies created."
	@echo "-> Library with bonus created."

-include $(DEPS_BONUS)


bonus: 
	@$(MAKE) $(BONUS)


clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(DEPS_DIR)
	@echo "-> Objects directory deleted successfully."
	@echo "-> Dependencies directory deleted successfully."


fclean: 
	@$(MAKE) clean
	@$(RM) $(NAME) $(BONUS)
	@echo "-> All files cleaned!"


re: 
	@$(MAKE) fclean 
	@$(MAKE) all


.PHONY: all clean fclean re bonus
