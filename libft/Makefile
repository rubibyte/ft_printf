# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xrodrigu <xrodrigu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 20:52:25 by xrodrigu          #+#    #+#              #
#    Updated: 2022/10/24 03:54:08 by xrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC_DIR = src

OBJ_DIR = .obj

DEP_DIR = .dep


#colors
NC = \033[0m
GREEN = \033[0;32m
RED = \033[0;31m


SRC = ft_bzero.c		ft_isalpha.c	ft_isprint.c 	ft_memcpy.c \
	  ft_strchr.c		ft_strlcpy.c 	ft_strnstr.c 	ft_toupper.c \
	  ft_calloc.c 		ft_isascii.c	ft_memchr.c 	ft_memmove.c \
	  ft_strdup.c 		ft_strlen.c  	ft_strrchr.c	ft_atoi.c \
	  ft_isalnum.c 		ft_isdigit.c 	ft_memcmp.c 	ft_memset.c \
	  ft_strlcat.c 		ft_strncmp.c 	ft_tolower.c 	ft_substr.c \
	  ft_putchar_fd.c	ft_putstr_fd.c 	ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_striteri.c		ft_strmapi.c 	ft_itoa.c 		ft_strjoin.c \
	  ft_strtrim.c		ft_split.c		ft_absval.c		ft_nbrlen.c


OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))


MAKEFILE = Makefile

AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror -W #-Ofast -O3 -fsanitize=address -g3

DEP_FLAGS = -MT $@ -MMD -MP

INCLUDE = -Iinclude/

RM = rm -f

RM_DIR = rm -rf


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MAKEFILE)
	@mkdir -p $(dir $@) $(DEP_DIR)/
	@$(CC) $(CFLAGS) $(DEP_FLAGS) $(INCLUDE) -c $< -o $@
	@mv $(patsubst %.o, %.d, $@) $(DEP_DIR)/

all: 
	@$(MAKE) $(NAME)


$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "${GREEN}[LIBFT]->Objects and dependencies created.${NC}"
	@echo "${GREEN}[LIBFT]->Library created.${NC}"


clean:
	@$(RM_DIR) $(OBJ_DIR) $(DEP_DIR)
	@echo "${GREEN}[LIBFT]->Objects directory ${RED}deleted${NC} ${GREEN}successfully.${NC}"
	@echo "${GREEN}[LIBFT]->Dependencies directory ${RED}deleted${NC} ${GREEN}successfully.${NC}"


fclean: 
	@$(MAKE) clean
	@$(RM) $(NAME)
	@echo "${GREEN}[LIBFT]->All files cleaned!${NC}"


re: 
	@$(MAKE) fclean 
	@$(MAKE) all


-include $(DEP)

.PHONY: all clean fclean re
