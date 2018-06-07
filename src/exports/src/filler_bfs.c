/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_dfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 04:46:06 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 04:46:06 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	filler_check_sides(t_bfs_list *const list, t_filler_map *const map)
{
	const unsigned	x = list->x[list->last];
	const unsigned	y = list->y[list->last];
	const unsigned	mark = list->mark[list->last];

	if (y != 0 && map->bfs[y - 1][x] == -1)
	{
		map->bfs[y - 1][x] = mark + 1;
		filler_push_bfs_list(list, x, y - 1, mark + 1);
	}
	if (y != map->y - 1 && map->bfs[y + 1][x] == -1)
	{
		map->bfs[y + 1][x] = mark + 1;
		filler_push_bfs_list(list, x, y + 1, mark + 1);
	}
	if (x != 0 && map->bfs[y][x - 1] == -1)
	{
		map->bfs[y][x - 1] = mark + 1;
		filler_push_bfs_list(list, x - 1, y, mark + 1);
	}
	if (x != map->x - 1 && map->bfs[y][x + 1] == -1)
	{
		map->bfs[y][x + 1] = mark + 1;
		filler_push_bfs_list(list, x + 1, y, mark + 1);
	}
}

void		filler_bfs(t_bfs_list *const list, t_filler_map *const map)
{
	while (list->last != list->first)
	{
		filler_check_sides(list, map);
		++list->last;
	}
}
