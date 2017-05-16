/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:33:36 by qrosa             #+#    #+#             */
/*   Updated: 2017/05/16 01:34:44 by yoko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "libft.h"

# define HASH_TAB_SIZE			2048

# define STATE_INIT				0
# define STATE_NB_ANT_OK		1
# define STATE_NAME_ROOM_OK		2
# define STATE_NAME_LINK_OK		3

# define ERR_NB_ANT				-1
# define ERR_NAME_ROOM			-2
# define ERR_NAME_LINK			-3

/*
** Main struct for project
*/
typedef struct			s_env
{
	unsigned int	nb_ant;
	char			*start_room;
	char			*end_room;
	char			**tab_rooms;

}						t_env;


int		main(int argc, char **argv);

void	free_struct(t_env **env);
t_env	*init_struct(void);
char	check_line(int state, char *current_line, t_env **env);
int		exit_error(int status, char *current_line, t_env **e);
bool	output_help(bool return_value);

void	debug_struct(t_env *env);

#endif
