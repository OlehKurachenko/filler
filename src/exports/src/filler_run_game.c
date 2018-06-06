/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_run_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:46:11 by okurache          #+#    #+#             */
/*   Updated: 2018/06/06 22:46:11 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

unsigned char	filler_run_game(t_fd_reader *const sin,
	const unsigned char player_n)
{
	while (sin->vt->is_readable) {
		if (filler_make_step(sin, player_n) != 0)
			return (1);
	}
	return (0);
}