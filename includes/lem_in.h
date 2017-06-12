/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/06/09 18:16:42 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "libft.h"
# include "libmatgraph.h"


# define HASHTAB_SIZE_NAME		128
# define HASHTAB_SIZE_COOR		128
# define LEN_SAVE_MAP_INIT		128
# define LEN_INDEX_ROOM			128

# define STATE_CHECK_ANT		0
# define STATE_CHECK_ROOM		1
# define STATE_CHECK_FIRST_LINK	2
# define STATE_CHECK_LINK		3
# define STATE_CHECK_END		4

/*
** Error values
*/
# define ERR_NB_ANT				-1
# define ERR_NAME_ROOM			-2
# define ERR_NAME_LINK			-3
# define ERR_EMPTY_ROOM			-4
# define ERR_ANT_OVERFLOW		-5
# define ERR_NO_ANT				-6
# define ERR_MAP_SCALE			-7
# define ERR_NAME_ROOM_L		-8
# define ERR_FIRST_LINE_EMPTY	-9
# define ERR_ADD_HASH			-10
# define ERR_ANT_START			-11
# define ERR_ANT_END			-12
# define ERR_NO_COOR			-13
# define ERR_CREATE_NODE		-14
# define ERR_SPE_ROOM			-15
# define ERR_ROOM_EXIST			-16
# define ERR_NO_ROOM			-17
# define ERR_MORE_ROOM			-18
# define ERR_SET_START			-19
# define ERR_SET_END			-20
# define ERR_NOTHING			-21
# define ERR_BAD_X_COOR			-22
# define ERR_COOR_X_OVERFLOW	-23
# define ERR_NO_Y_COOR			-24
# define ERR_BAD_Y_COOR			-25
# define ERR_COOR_Y_OVERFLOW	-26
# define ERR_CREATE_NODE_COOR	-27
# define ERR_COOR_EXIST			-28
# define ERR_START_LINK			-29
# define ERR_END_LINK			-30
# define ERR_NO_BEGIN_NAME		-31
# define ERR_NAME_LINK_L		-32
# define ERR_FORMAT_LINK		-33
# define ERR_NAME_LINK1_NOMATCH -34
# define ERR_DOUBLE_DASH		-35
# define ERR_NAME_LINK2_NOMATCH -36
# define ERR_ADD_NAME_INDEX		-37
# define ERR_REALLOC_INDEX_ROOM -38

# define LAST_ERROR				39

/*
** Define special room
*/
# define SPE_BASIC_ROOM			0
# define SPE_START_ROOM			1
# define SPE_END_ROOM			2

typedef struct		s_ant
{
	t_path			*path;
	unsigned long	path_position;
}					t_ant;

typedef struct		s_anthill
{
	t_ant			*ants;
	unsigned long	waiting_ants;
}					t_anthill;
void				print_solution(t_path **paths, unsigned long lemins,
								   unsigned long turns);

/*
**	Norme compliant
*/
typedef unsigned long u_long;

/*
** Hashtab name struct
*/
typedef struct			s_hash
{
	char				*room_name;
	unsigned int		index_room;
	struct s_hash		*next;
}						t_hash;

/*
** Hashtab coordinates struct
*/
typedef struct			s_hash_coor
{
	int					x_coor;
	int					y_coor;
	struct s_hash_coor	*next;
}						t_hash_coor;

/*
** Main struct for project
*/
typedef struct			s_env
{
	char			*save_map;
	char			**index_room;
	unsigned int	index_room1;
	unsigned int	index_room2;
	unsigned int	len_map;
	unsigned int	pos_map;
	unsigned int	nb_ant;
	unsigned int	nb_room;
	unsigned int	nb_link;
	unsigned int	nb_line;
	char			special_room;
	int				start_room;
	int				end_room;
	t_hash			**tab_rooms;
	t_hash_coor		**tab_coor;
	t_matrice_graph	*graph;
}						t_env;

int				main(int argc, char **argv);

t_env			*init_struct(void);
unsigned long	hash_djb2(unsigned char *str);
void			free_struct(t_env **env);
void			*free_hashtab(t_env **env, bool type);
int				exit_error(char status, char *current_line, t_env **e);
bool			output_help(bool return_value);

bool			buff_add_str(t_env **env, char *current_line);
bool			check_ascii_range(char *str, char *model);
int				browse_space(char *current_line, int i);

/*
**	Check line functions
*/
char			check_line(char state, char *current_line, t_env **env);
char			check_status_empty_line(char status);
char			check_nb_ant(char *current_line, t_env **env);
char			valid_and_set_room(char *current_line, t_env **env);
char			check_room(char *current_line, t_env **env);
char			check_special_line(char *current_line, t_env **env);
char			check_name_room(char *current_line, t_env **env, int *i);
char			add_name_ptr_index(t_env **env, char *room_name);
char			check_coor_room(char *current_line, t_env **env, int *i);
char			check_n_max_int(char *current_line, int start, int len);
char			check_room_step_valid(t_env **env);
char			check_links(char *current_line, t_env **env);
char			valid_and_set_links(char *current_line, t_env **env);

/*
**	TMP Declarations
*/
void			debug_struct(t_env *env);

t_path			**get_optimum_paths(t_matrice_graph *graph, unsigned long src,
									  unsigned long dst, unsigned long lemins);
int				resolve(t_env *env);

#endif
