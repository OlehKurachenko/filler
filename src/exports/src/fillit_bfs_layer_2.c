/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bfs_layer_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:35:34 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 07:35:34 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			prepare_cell(t_bfs_list *const list,
		t_filler_map *const map, const size_t i, const size_t j)
{
	if (map->raw[i][j] == '*' || map->bfs[i][j] != -1)
	{
		if (i == 0 || i == map->y - 1 || j == 0 || j == map->x - 1
			|| map->raw[i - 1][j] != '.' || map->raw[i + 1][j] != '.'
			|| map->raw[i][j - 1] != '.' || map->raw[i][j + 1] != '.')
		{
			filler_push_bfs_list(list, j, i, 0);
			map->bfs[i][j] = 0;
		}
		else
		{
			map->bfs[i][j] = -1;
		}
	}
	else
		map->bfs[i][j] = 0;
}

void				prepare_from_border_bfs(t_bfs_list *const list,
		t_filler_map *const map)
{
	size_t i;
	size_t j;

	list->first = 0;
	list->last = 0;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			prepare_cell(list, map, i, j);
			++j;
		}
		++i;
	}
}