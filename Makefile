# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2017/05/19 16:29:14 by qrosa            ###   ########.fr        #
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
					$(PATH_SOURCES)free_struct.c\
					$(PATH_SOURCES)exit_error.c \
					$(PATH_SOURCES)output_help.c \
					\
					$(PATH_SOURCES)debug_struct.c

SRCS_CHECK_LINE =	$(PATH_CHECK_LINE)check_line.c \
					$(PATH_CHECK_LINE)check_nb_ant.c \
					$(PATH_CHECK_LINE)check_status_empty_line.c \
					$(PATH_CHECK_LINE)check_room_name.c \
					$(PATH_CHECK_LINE)valid_and_set_room.c \
					$(PATH_CHECK_LINE)add_to_hashtab_name.c \

################################################################################

#	Object Rules Declarations
OBJ			=	$(SRCS:.c=.o) \
				$(SRCS_CHECK_LINE:.c=.o) \

# Lib includes
INC			=	-I ./includes/
LIBFT		=	libft/libft.a
LFT			=	-L ./libft/ -lft

# Options can be changed
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_OBJ	=	-Wall -Wextra -Werror
DEBUG_F		=	-g
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

$(LIBFT):
				@make -C libft

$(NAME): 		$(OBJ) libft/ Makefile
				@echo "${BLUE}-- Linking $(NAME)${NC}"
				@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LFT)

%.o: %.c
				@echo "${CYAN}Compiling $^ into $@ ${NC}";
				@$(CC) $(DEBUG_F) -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
				@make clean -C libft
				@echo "${YELLOW}-- Delete lem_in/libft		Objects OK ${NC}";
				@rm -f $(OBJ)

fclean: 		clean
				@echo "${RED}-- Remove $(LIBFT)			OK${NC}"
				@rm -f $(LIBFT)
				@echo "${RED}-- Remove $(NAME)			OK${NC}"
				@rm -f $(NAME)

re: 			fclean all

rdb: 			fclean db

.PHONY: 		all clean fclean re db rdb
