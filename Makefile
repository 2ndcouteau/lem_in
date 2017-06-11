# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2017/06/09 22:49:32 by yoko             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#																			   #
#   				-- MAKEFILE for Lem_in project --						   #
#																			   #
################################################################################

#	ROOT_PATH && DIRECTORIES
PATH_SOURCES	=		./srcs/

PATH_CHECK_LINE =		$(PATH_SOURCES)check_line/
# PATH_LEXPAR			=	$(PATH_SOURCES)lexer_parser/
# PATH_FREE				=	$(PATH_SOURCES)free/


################################################################################

#	FILES DECLARATIONS
SRCS			=	$(PATH_SOURCES)main.c \
					$(PATH_SOURCES)init_struct.c \
					$(PATH_SOURCES)hash_function_djb2.c \
					$(PATH_SOURCES)buff_add_str.c \
					$(PATH_SOURCES)browse_space.c \
					$(PATH_SOURCES)free_struct.c\
					$(PATH_SOURCES)exit_error.c \
					$(PATH_SOURCES)output_help.c \
					\
					$(PATH_SOURCES)debug_struct.c

SRCS_CHECK_LINE =	$(PATH_CHECK_LINE)check_line.c \
					$(PATH_CHECK_LINE)check_nb_ant.c \
					$(PATH_CHECK_LINE)check_status_empty_line.c \
					$(PATH_CHECK_LINE)check_room.c \
					$(PATH_CHECK_LINE)valid_and_set_room.c \
					$(PATH_CHECK_LINE)check_special_line.c \
					$(PATH_CHECK_LINE)check_name_room.c \
					$(PATH_CHECK_LINE)add_name_ptr_index.c \
					$(PATH_CHECK_LINE)check_coor_room.c \
					$(PATH_CHECK_LINE)check_n_max_int.c \
					$(PATH_CHECK_LINE)check_room_step_valid.c \
					$(PATH_CHECK_LINE)check_links.c \
					$(PATH_CHECK_LINE)valid_and_set_links.c

################################################################################

#	Object Rules Declarations
OBJ			=	$(SRCS:.c=.o) \
				$(SRCS_CHECK_LINE:.c=.o) \

# Lib includes
INC			=	-I ./includes/
LIBFT		=	libft/libft.a
LIBGRAPH	=	libgraph/libgraph.a
LFT			=	-L ./libft/ -lft
LGF			=	-L ./libgraph/ -lgraph

# Options can be changed
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_OBJ	=	-Wall -Wextra -Werror
DEBUG_F		=	-O0 -g3
CC			=	gcc
NAME		=	lem-in

# Sweet colors just for swag :)
RED			=	\033[0;31m
BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
YELLOW		=	\033[0;33m
GREEN		=	\033[1;32m
NC			=	\033[0m

################################################################################

#	Make Rules
all: 			$(LIBFT) $(NAME)

debug:
				$(eval CFLAGS_OBJ += -DDEBUG)

db: 			debug all

$(LIBGRAPH):
				@make -C libgraph

$(LIBFT):
				@make -C libft

$(NAME): 		$(OBJ) libft/ libgraph/ Makefile
				@echo "${BLUE}-- Linking $(NAME)${NC}"
				@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LFT) $(LGF)

%.o: %.c
				@echo "${CYAN}Compiling $^ into $@ ${NC}";
				@$(CC) $(DEBUG_F) -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
				@make clean -C libft
				@make clean -C libgraph
				@echo "${YELLOW}-- Delete lem_in/libft		Objects OK ${NC}";
				@rm -f $(OBJ)

fclean: 		clean
				@echo "${RED}-- Remove $(LIBFT)			OK${NC}"
				@make -C fclean libft
				@make -C fclean libgraph
				@echo "${RED}-- Remove $(NAME)			OK${NC}"
				@rm -f $(NAME)

re: 			fclean all

rdb: 			fclean db

.PHONY: 		all clean fclean re db rdb
