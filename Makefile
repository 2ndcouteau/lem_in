# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by qrosa             #+#    #+#              #
#    Updated: 2017/06/29 14:47:38 by qrosa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#																			   #
#   				-- MAKEFILE for Lem_in project --						   #
#																			   #
################################################################################

#	ROOT_PATH && DIRECTORIES
PATH_SOURCES	=		./srcs/

PATH_CHECK_LINE	=		$(PATH_SOURCES)check_line/
PATH_LIBGRAPH	=		$(PATH_SOURCES)libgraph/

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
					$(PATH_SOURCES)get_optimum_paths.c \
					$(PATH_SOURCES)resolve.c \
					$(PATH_SOURCES)print_solution.c \
					$(PATH_SOURCES)print_ants.c \
					$(PATH_SOURCES)print_direct_way.c \
					$(PATH_SOURCES)push_to_paths.c

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

SRCS_LIBGRAPH	=	$(PATH_LIBGRAPH)delete_matrice_graph.c \
					$(PATH_LIBGRAPH)get_link.c \
					$(PATH_LIBGRAPH)invert_link.c \
					$(PATH_LIBGRAPH)negate_link.c \
					$(PATH_LIBGRAPH)new_matrice_graph.c \
					$(PATH_LIBGRAPH)set_link.c \
					$(PATH_LIBGRAPH)toggle_link.c \
					$(PATH_LIBGRAPH)unset_link.c \
					$(PATH_LIBGRAPH)new_path.c \
					$(PATH_LIBGRAPH)new_pathfind.c \
					$(PATH_LIBGRAPH)delete_path.c \
					$(PATH_LIBGRAPH)delete_pathfind.c \
					$(PATH_LIBGRAPH)pathfind_to_path.c \
					$(PATH_LIBGRAPH)graph_to_paths.c \
					$(PATH_LIBGRAPH)add_path_to_graph.c \
					$(PATH_LIBGRAPH)bellman_ford.c \
					$(PATH_LIBGRAPH)dijkstra.c \
					$(PATH_LIBGRAPH)bhandari.c

################################################################################

#	Object Rules Declarations
OBJ			=	$(SRCS:.c=.o) \
				$(SRCS_CHECK_LINE:.c=.o) \
				$(SRCS_LIBGRAPH:.c=.o)

# Lib includes
INC			=	-I ./includes/
LIBFT		=	libft/libft.a
LFT			=	-L ./libft/ -lft

# Options can be changed
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS_OBJ	=	-Wall -Wextra -Werror
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

$(NAME): 		$(OBJ) Makefile libft/
				@echo "${BLUE}-- Linking $(NAME)${NC}"
				@$(CC) $(OBJ) -o $(NAME) $(INC) $(LFT) $(LGF)

%.o: %.c
				@echo "${CYAN}Compiling $^ into $@ ${NC}";
				@$(CC) -c $^ -o $@ $(CFLAGS_OBJ) $(INC)

clean:
				@echo "${YELLOW}-- Call clean libft Obj		OK ${NC}";
				@make clean -C libft
				@rm -f $(OBJ)

fclean: 		clean
				@echo "${RED}-- Delete $LIBFT			OK${NC}";
				@rm -f $(LIBFT)
				@echo "${RED}-- Delete $LIBGRAPH		OK${NC}";
				@rm -f $(NAME)

re: 			fclean all

rdb: 			fclean db

.PHONY: 		all clean fclean re db rdb
