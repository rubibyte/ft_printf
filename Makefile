# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/16 22:12:25 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = libft

SRC_DIR = src

UTL_DIR = utils

FT_PRINTF_DIR = ft_printf

WRITE_DIR = write

AUX_DIR = aux

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


SRC =	ft_printf.c

AUX_UTL =	ft_arg_data.c				ft_check_format.c \
			ft_check_valid_format.c		ft_fetch_arg_data.c \
			ft_precision_utils.c

FT_PRINTF_UTL = ft_printf_arg.c			ft_printf_char.c \
				ft_printf_int.c			ft_printf_str.c \
				ft_printf_unsigned_int.c \
				ft_printf_unsigned_int_hex.c \
				ft_printf_void_ptr_hex.c

WRITE_UTL = 	ft_write_int.c			ft_write_padding.c \
				ft_write_str.c			ft_write_uint_base.c \
				ft_write_void_ptr_hex.c


SRCS += $(addprefix $(SRC_DIR)/, $(SRC))
SRCS += $(addprefix $(UTL_DIR)/$(AUX_DIR)/, $(AUX_UTL))
SRCS += $(addprefix $(UTL_DIR)/$(FT_PRINTF_DIR)/, $(FT_PRINTF_UTL))
SRCS += $(addprefix $(UTL_DIR)/$(WRITE_DIR)/, $(WRITE_UTL))

OBJ_SRCS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

DEPS += $(addprefix $(DEP_DIR)/, $(addsuffix .d, $(basename $(SRCS))))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-fsanitize=address #-Ofast -O3 -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/ -Ilibft/include/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: %.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(dir $(subst $(OBJ_DIR)/, $(DEP_DIR)/, $@))
	@printf "${DEL_LINE}\r${CYAN}[FT_PRINTF]compiling... $@${NC}"
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


clean:
#------------------------ libft cleaning ---------------------------------
	@$(MAKE) clean -C libft/
#-------------------------------------------------------------------------
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@printf "${GREEN}[FT_PRINTF]->Objects directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"
	@printf "${GREEN}[FT_PRINTF]->Dependencies directory${RED}deleted${NC} ${GREEN}successfully.${NC}\n"


fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) $(LIBFT_DIR)/$(LIBFT)
	@printf "${GREEN}[FT_PRINTF]->All files cleaned!${NC}"


re:
	@$(MAKE) fclean
	@$(MAKE) all


-include $(DEPS)

.PHONY: all clean fclean re
