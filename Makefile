# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/16 16:21:07 by xrodrigu         ###   ########.fr        #
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
DEL_LINE =  \033[2K
NC =		\033[0m
BLACK = 	\033[0;30m
RED = 		\033[0;31m
GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
BLUE = 		\033[0;34m
PURPLE = 	\033[0;35m
CYAN =	 	\033[0;36m
WHITE = 	\033[0;37m


SRC = 	ft_printf.c

UTL = 	ft_printf_int.c			ft_printf_str.c \
	  	ft_printf_uint_base.c	ft_printf_void_ptr_hex.c

BNS_SRC = ft_printf_bonus.c

BNS_UTL = ft_arg_data_bonus.c \
		  ft_check_format_bonus.c \
		  ft_check_valid_format_bonus.c \
		  ft_fetch_arg_data_bonus.c \
		  ft_precision_utils_bonus.c \
		  ft_printf_arg_bonus.c \
		  ft_printf_char_bonus.c \
		  ft_printf_int_bonus.c \
		  ft_printf_str_bonus.c \
		  ft_printf_unsigned_int_bonus.c \
		  ft_printf_unsigned_int_hex_bonus.c \
		  ft_printf_void_ptr_hex_bonus.c \
		  ft_write_int_bonus.c \
		  ft_write_padding_bonus.c \
		  ft_write_str_bonus.c \
		  ft_write_uint_base_bonus.c \
		  ft_write_void_ptr_hex_bonus.c


SRCS += $(addprefix $(SRC_DIR)/, $(SRC))
SRCS += $(addprefix $(UTL_DIR)/, $(UTL))

BNS_SRCS += $(addprefix $(BNS_DIR)/$(SRC_DIR)/, $(BNS_SRC))
BNS_SRCS += $(addprefix $(BNS_DIR)/$(UTL_DIR)/, $(BNS_UTL))

OBJ_SRCS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

OBJ_BNS_SRCS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(BNS_SRCS))))

DEPS += $(addprefix $(DEP_DIR)/, $(addsuffix .d, $(basename $(SRCS))))
DEPS += $(addprefix $(DEP_DIR)/, $(addsuffix .d, $(basename $(BNS_SRCS))))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/ -Ilibft/include/ -Ibonus/include/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: %.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@printf "${DEL_LINE}\r${CYAN}[FT_PRINTF/FT_PRINTF_BONUS]compiling... $@${NC}"
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))


all:
	@$(MAKE) $(NAME)


$(NAME): $(OBJ_SRCS)
#---------------------- libft compilation --------------------------------
	@$(MAKE) -C $(LIBFT_DIR)/
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@printf "${DEL_LINE}\r${GREEN}[FT_PRINTF]->Objects and dependencies compiled.${NC}\n"
	@$(AR) $(NAME) $(OBJ_SRCS)
	@printf "${GREEN}[FT_PRINTF]->Library created.${NC}\n"


$(BONUS): $(OBJ_BNS_SRCS)
	@touch $@
#---------------------- libft compilation --------------------------------
	@$(MAKE) -C $(LIBFT_DIR)/
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@printf "${DEL_LINE}\r${GREEN}[FT_PRINTF_BONUS]->Objects and dependencies compiled.${NC}\n"
	@$(AR) $(NAME) $(OBJ_BNS_SRCS)
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


-include $(DEPS)

.PHONY: all clean fclean re bonus
