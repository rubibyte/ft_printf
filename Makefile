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

NAME = libft.a

OBJ_DIR = objects



SRC = 

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEPS = $(addsuffix .d, $(basename $(OBJS)))



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


clean:
	@$(RM) $(OBJ_DIR)
	@echo "-> Objects directory deleted successfully."



fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "-> All files cleaned!"



re: fclean all


.PHONY: all bonus clean fclean re bonus
