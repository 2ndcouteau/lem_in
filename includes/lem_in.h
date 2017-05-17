/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/17 18:01:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "libft.h"

# define HASH_TAB_SIZE			2048
# define LEN_SAVE_MAP_INIT		2048

# define STATE_CHECK_ANT		0
# define STATE_CHECK_ROOM		1
# define STATE_CHECK_LINK		2
# define STATE_CHECK_END		3

# define ERR_NB_ANT				-1
# define ERR_NAME_ROOM			-2
# define ERR_NAME_LINK			-3
# define ERR_EMPTY_ROOM			-4
# define ERR_ANT_OVERFLOW		-5
# define ERR_NO_ANT				-6
# define ERR_MAP_SCALE			-7
# define ERR_NAME_ROOM_L		-8
# define ERR_FIRST_LINE_EMPTY	-9

/*
** Hash_tab struct
*/
typedef struct			s_hash
{
	char				*room_name;
	struct s_hash		*next;
}						t_hash;

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
	char			state_room;
	char			*start_room;
	char			*end_room;
	t_hash			**tab_rooms;

}						t_env;

int				main(int argc, char **argv);

t_env			*init_struct(void);
unsigned long	hash_djb2(unsigned char *str);
void			free_struct(t_env **env);
int				exit_error(char status, char *current_line, t_env **e);
bool			output_help(bool return_value);

bool			buff_add_str(t_env **env, char *current_line);

/*
**	Check line functions
*/
char			check_line(char state, char *current_line, t_env **env);
char			check_status_empty_line(char status);
char			check_nb_ant(char *current_line, t_env **env);

/*
**	TMP Declarations
*/
void			debug_struct(t_env *env);

#endif
