/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:48:13 by okurache          #+#    #+#             */
/*   Updated: 2018/06/06 17:48:13 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

#include <stdio.h>
#include <stdlib.h>
# include "../../../imports/okurache_libft/libft.h"
# include "../../../imports/okurache_libftin/libftin.h"
# include "../../../imports/okurache_ft_printf/ft_printf.h"

/*
**	Weight coefficient of points for distance to opponent
*/
static const double	g_distance_to_opponent_w = 1.0;

/*
**	Weight coefficient of points for distance form border
*/
static const double	g_distance_from_border_w = 1.0;

typedef struct 		s_filler_map {
	char		**raw;
	unsigned	**dfs;
	double		**points;
	unsigned	x;
	unsigned	y;
}					t_filler_map;

typedef struct 		s_filler_token {
	char		**raw;
	unsigned	x;
	unsigned	y;
}					t_filler_token;

unsigned char		filler_run_game(t_fd_reader *const sin,
		const unsigned char player_n);

unsigned char		filler_make_step(t_fd_reader *const sin,
		const unsigned char player_n);

#endif
