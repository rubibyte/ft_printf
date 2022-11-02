# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 19:40:11 by xrodrigu          #+#    #+#              #
#    Updated: 2022/11/01 20:33:07 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFT_DIR = libft

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

LINE = ${PURPLE}═══════════════════════════${NC}
#╔═══════════════╗
#	L I B F T
#╚═══════════════╝


SRC = ft_fetch_arg_data.c	ft_printf.c			ft_printf_arg.c \
	  ft_printf_char.c		ft_printf_int.c 	ft_printf_str.c	\
	  ft_printf_unsigned_int.c 					ft_printf_unsigned_int_hex.c \
	  ft_printf_void_ptr_hex.c 					ft_there_is.c \
	  ft_unsignedtoa_base.c	ft_write_int.c		ft_write_padding.c \
	  ft_write_str.c		ft_write_uint_base.c \
	  ft_write_void_ptr_hex.c 					precision_utils.c

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
	@mkdir -p $(dir $@) $(DEP_DIR)/
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(DEP_DIR)/


all:
	@$(MAKE) $(NAME)


$(NAME): $(OBJ)
#---------------------- libft compilation --------------------------------
	@echo "                          ${PURPLE}╔═══════════════╗${NC}"
	@echo "$(LINE)   ${BLUE}L I B F T${NC}   $(LINE)"
	@echo "                          ${PURPLE}╚═══════════════╝${NC}"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(LINE)$(LINE)${PURPLE}═══════════════${NC}"
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
#-------------------------------------------------------------------------
	@$(AR) $(NAME) $(OBJ)
	@echo "${GREEN}Objects and dependencies created.${NC}"
	@echo "${GREEN}Library created.${NC}"


clean:
#------------------------ libft cleaning ---------------------------------
	@echo "                          ${PURPLE}╔═══════════════╗${NC}"
	@echo "$(LINE)   ${BLUE}L I B F T${NC}   $(LINE)"
	@echo "                          ${PURPLE}╚═══════════════╝${NC}"
	@$(MAKE) clean -C libft/
	@echo "$(LINE)$(LINE)${PURPLE}═══════════════${NC}"
#-------------------------------------------------------------------------
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@echo "${GREEN}Objects directory${RED}deleted${NC} ${GREEN}successfully.${NC}"
	@echo "${GREEN}Dependencies directory${RED}deleted${NC} ${GREEN}successfully.${NC}"


fclean:
	@$(MAKE) clean
	@$(RM) $(NAME) $(LIBFT_DIR)/$(LIBFT)
	@echo "${GREEN}All files cleaned!${NC}"


re: 
	@$(MAKE) fclean 
	@$(MAKE) all


-include $(DEP)

.PHONY: all clean fclean re
