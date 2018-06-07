/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_read_raw_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 03:35:30 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 03:35:30 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static unsigned char	init_filler_map(t_filler_map *const map)
{
	size_t	i;

	map->raw = (char **)malloc(sizeof(char *) * map->y);
	map->bfs = (int **)malloc(sizeof(int *) * map->y);
	map->points = (double **)malloc(sizeof(double *) * map->y);
	if (!map->raw || !map->bfs || !map->points)
		return (1);
	i = 0;
	while (i < map->y)
	{
		map->raw[i] = (char *)malloc(sizeof(char) * (map->x + 1));
		map->bfs[i] = (int *)malloc(sizeof(int) * map->x);
		map->points[i] = (double *)malloc(sizeof(double) * map->x);
		if (!map->points[i] || !map->raw[i] || !map->bfs[i])
			return (1);
		++i;
	}
	return (0);
}

unsigned char		filler_read_raw_map(t_fd_reader *const sin,
		t_filler_map *const map)
{
	char 	dummy_buffer[7];
	size_t	i;

	ft_memset(dummy_buffer, 0, 7);
	sin->vt->read_line_to_array(sin, dummy_buffer, 7);
	if (!ft_strnequ(dummy_buffer, "Plateau", 7))
		return (1);
	map->y = (unsigned)sin->vt->read_llint(sin);
	map->x = (unsigned)sin->vt->read_llint(sin);
	if (!(map->x) || !(map->y))
		return (1);
	if (!map->raw)
		if (init_filler_map(map))
			return (1);
	sin->vt->pass_line(sin);
	sin->vt->pass_line(sin);
	i = 0;
	while (i < map->y)
	{
		sin->vt->read_line_to_array(sin, dummy_buffer, 4);
		sin->vt->read_line_to_array(sin, map->raw[i], map->x + 1);
		if (map->raw[i][map->x] || ft_strlen(map->raw[i]) != map->x)
			return (1);
		++i;
	}
	return (0);
}