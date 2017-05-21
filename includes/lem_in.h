/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/21 06:55:13 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "libft.h"

# define HASHTAB_SIZE_NAME		128
# define HASHTAB_SIZE_COOR		128
# define LEN_SAVE_MAP_INIT		32

# define STATE_CHECK_ANT		0
# define STATE_CHECK_ROOM		1
# define STATE_CHECK_LINK		2
# define STATE_CHECK_END		3

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

/*
** Define special room
*/
# define SPE_BASIC_ROOM			0
# define SPE_START_ROOM			1
# define SPE_END_ROOM			2

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
	unsigned int	len_map;
	unsigned int	pos_map;
	unsigned int	nb_ant;
	unsigned int	nb_room;
	unsigned int	nb_link;
	char			special_room;
	char			*start_room;
	char			*end_room;
	t_hash			**tab_rooms;
	t_hash_coor		**tab_coor;
}						t_env;

int				main(int argc, char **argv);

t_env			*init_struct(void);
unsigned long	hash_djb2(unsigned char *str);
void			free_struct(t_env **env);
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
char			check_name_room(char *current_line, t_env **env, int *i);
char			check_coor_room(char *current_line, t_env **env, int *i);
char			check_n_max_int(char *current_line, int start, int len);

/*
**	TMP Declarations
*/
void			debug_struct(t_env *env);

#endif
