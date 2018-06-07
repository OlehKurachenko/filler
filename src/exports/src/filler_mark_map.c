/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_mark_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:29:22 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 03:29:22 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static unsigned char	init_bfs_list(t_bfs_list *const list, const size_t size)
{
	list->x = (unsigned *)malloc(size * sizeof(unsigned));
	list->y = (unsigned *)malloc(size * sizeof(unsigned));
	list->mark = (unsigned *)malloc(size * sizeof(unsigned));

	if (!list->x || !list->y || !list->mark)
		return (1);
	return (0);
}

static void				preprate_to_opponent_bfs(t_bfs_list *const list,
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
			if (map->raw[i][j] == map->op_char)
			{
				filler_push_bfs_list(list, j, i, 0);
				map->bfs[i][j] = 0;
			}
			else if (map->raw[i][j] == map->my_char)
				map->bfs[i][j] = 0;
			else
				map->bfs[i][j] = -1;
			++j;
		}
		++i;
	}
}

static void				fill_map_points_to_opponent_bfs(t_filler_map *const map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->raw[i][j] == '.')
				map->points[i][j] = g_distance_to_opponent_w *
					((map->bfs[i][j] < 0) ? 0
							: map->x + map->y - map->bfs[i][j]);
			else
				map->points[i][j] = 0;
			++j;
		}
		++i;
	}
}

unsigned char			filler_mark_map(t_filler_map *const map)
{
	static t_bfs_list	bfs_list = {NULL, NULL, NULL, 0, 0};

	if (!bfs_list.x && init_bfs_list(&bfs_list, map->x * map->y))
		return (1);
	preprate_to_opponent_bfs(&bfs_list, map);
	filler_bfs(&bfs_list, map);
	fill_map_points_to_opponent_bfs(map);

	//Check section
	printf("Map size: %u %u\n", map->y, map->x);
	for (unsigned i = 0; i < map->y; ++i) {
		for (unsigned j = 0; j < map->x; ++j)
			printf("%4d|", map->bfs[i][j]);
		printf("\n");
	}
	printf("Map size: %u %u\n", map->y, map->x);
	for (unsigned i = 0; i < map->y; ++i) {
		for (unsigned j = 0; j < map->x; ++j)
			printf("%4.1f|", map->points[i][j]);
		printf("\n");
	}
	fflush(stdin);
	//Check section

	return (0);
}