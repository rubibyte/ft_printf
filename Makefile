# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/07 23:20:45 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = libft

SRC_DIR = src

UTILS_DIR = utils

OBJ_DIR = .obj

DEP_DIR = .dep


#colors
NC = \033[0m
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m


SRC = 	src/ft_printf.c

UTILS = utils/ft_printf_int.c			utils/ft_printf_str.c \
	  	utils/ft_printf_uint_base.c		utils/ft_printf_void_ptr_hex.c

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP_SRC = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))

OBJ_UTILS = $(addprefix $(OBJ_DIR)/, $(UTILS:.c=.o))

DEP_UTILS = $(addprefix $(DEP_DIR)/, $(UTILS:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/ -Ilibft/include/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


$(OBJ_DIR)/$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


all:
	@$(MAKE) $(NAME)


$(NAME): $(OBJ_SRC) $(OBJ_UTILS)
#---------------------- libft compilation --------------------------------
	@$(MAKE) -C $(LIBFT_DIR)/
	@mv $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@$(AR) $(NAME) $(OBJ_SRC) $(OBJ_UTILS)
	@printf "${GREEN}Objects and dependencies created.${NC}\n"
	@printf "${GREEN}Library created.${NC}\n"


clean:
#------------------------ libft cleaning ---------------------------------
	@$(MAKE) clean -C libft/
#-------------------------------------------------------------------------
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@printf "${GREEN}Objects directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"
	@printf "${GREEN}Dependencies directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"


fclean:
	@$(MAKE) clean
	@$(RM) $(NAME)
	@printf "${GREEN}All files cleaned!${NC}"


re:
	@$(MAKE) fclean
	@$(MAKE) all


-include $(DEP_SRC) $(DEP_UTILS)

.PHONY: all clean fclean re
