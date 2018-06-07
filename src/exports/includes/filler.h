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
	int			**bfs;
	double		**points;
	unsigned	x;
	unsigned	y;
}					t_filler_map;

typedef struct 		s_filler_token {
	char		**raw;
	unsigned	x;
	unsigned	y;
}					t_filler_token;

typedef struct		s_bfs_list {
	unsigned		*x;
	unsigned		*y;
	unsigned		*mark;
	size_t			first;
	size_t			last;
	char 			my_char;
	char 			op_char;
}					t_bfs_list;

unsigned char		filler_run_game(t_fd_reader *const sin,
		const unsigned char player_n);

unsigned char		filler_make_step(t_fd_reader *const sin,
		const unsigned char player_n);

/*
**	Also initialize map arrays it they are not yet initialized
*/

unsigned char		filler_read_raw_map(t_fd_reader *const sin,
		t_filler_map *const map);

unsigned char			filler_mark_map(t_filler_map *const map,
		const unsigned char player_n);

void		filler_bfs(t_bfs_list *const list, t_filler_map *const map);

void	filler_push_bfs_list(t_bfs_list *const list, const unsigned x,
		const unsigned y, const unsigned mark);

#endif
