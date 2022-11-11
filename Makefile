# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/11 19:55:01 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

BONUS = .bonus

LIBFT_DIR = libft

SRC_DIR = src

UTL_DIR = utils

BNS_DIR = bonus

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

UTL = 	utils/ft_printf_int.c				utils/ft_printf_str.c \
	  	utils/ft_printf_uint_base.c			utils/ft_printf_void_ptr_hex.c

BNS_SRC = bonus/src/ft_printf_bonus.c

BNS_UTL = bonus/utils/ft_arg_data_bonus.c \
		  bonus/utils/ft_check_format_bonus.c \
		  bonus/utils/ft_check_valid_format_bonus.c \
		  bonus/utils/ft_fetch_arg_data_bonus.c \
		  bonus/utils/ft_precision_utils_bonus.c \
		  bonus/utils/ft_printf_arg_bonus.c \
		  bonus/utils/ft_printf_char_bonus.c \
		  bonus/utils/ft_printf_int_bonus.c \
		  bonus/utils/ft_printf_str_bonus.c \
		  bonus/utils/ft_printf_unsigned_int_bonus.c \
		  bonus/utils/ft_printf_unsigned_int_hex_bonus.c \
		  bonus/utils/ft_printf_void_ptr_hex_bonus.c \
		  bonus/utils/ft_write_int_bonus.c \
		  bonus/utils/ft_write_padding_bonus.c \
		  bonus/utils/ft_write_str_bonus.c \
		  bonus/utils/ft_write_uint_base_bonus.c \
		  bonus/utils/ft_write_void_ptr_hex_bonus.c


OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP_SRC = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))

OBJ_UTL = $(addprefix $(OBJ_DIR)/, $(UTL:.c=.o))

DEP_UTL = $(addprefix $(DEP_DIR)/, $(UTL:.c=.d))

OBJ_BNS_SRC = $(addprefix $(OBJ_DIR)/, $(BNS_SRC:.c=.o))

DEP_BNS_SRC = $(addprefix $(DEP_DIR)/, $(BNS_SRC:.c=.d))

OBJ_BNS_UTL = $(addprefix $(OBJ_DIR)/, $(BNS_UTL:.c=.o))

DEP_BNS_UTL = $(addprefix $(DEP_DIR)/, $(BNS_UTL:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/ -Ilibft/include/ -Ibonus/include/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))

$(OBJ_DIR)/$(UTL_DIR)/%.o: $(UTL_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


$(OBJ_DIR)/$(BNS_DIR)/$(SRC_DIR)/%.o: $(BNS_DIR)/$(SRC_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))

$(OBJ_DIR)/$(BNS_DIR)/$(UTL_DIR)/%.o: $(BNS_DIR)/$(UTL_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


all:
	@$(MAKE) $(NAME)


$(NAME): $(OBJ_SRC) $(OBJ_UTL)
#---------------------- libft compilation --------------------------------
	@$(MAKE) -C $(LIBFT_DIR)/
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@$(AR) $(NAME) $(OBJ_SRC) $(OBJ_UTL)
	@printf "${GREEN}[FT_PRINTF]->Objects and dependencies created.${NC}\n"
	@printf "${GREEN}[FT_PRINTF]->Library created.${NC}\n"


$(BONUS): $(OBJ_BNS_SRC) $(OBJ_BNS_UTL)
	@touch $@
#---------------------- libft compilation --------------------------------
	@$(MAKE) -C $(LIBFT_DIR)/
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@$(AR) $(NAME) $(OBJ_BNS_SRC) $(OBJ_BNS_UTL)
	@printf "${GREEN}[FT_PRINTF_BONUS]->Objects and dependencies created.${NC}\n"
	@printf "${GREEN}[FT_PRINTF_BONUS]->Library created.${NC}\n"


bonus:
	@$(MAKE) $(BONUS)


clean:
#------------------------ libft cleaning ---------------------------------
	@$(MAKE) clean -C libft/
#-------------------------------------------------------------------------
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@printf "${GREEN}[FT_PRINTF]->Objects directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"
	@printf "${GREEN}[FT_PRINTF]->Dependencies directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"


fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) $(BONUS) $(LIBFT_DIR)/$(LIBFT)
	@printf "${GREEN}[FT_PRINTF]->All files cleaned!${NC}"


re:
	@$(MAKE) fclean
	@$(MAKE) all


-include $(DEP_SRC) $(DEP_UTL) $(DEP_BNS_SRC) $(DEP_BNS_UTL)

.PHONY: all clean fclean re bonus
