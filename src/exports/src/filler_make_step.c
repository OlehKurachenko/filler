/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_make_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 22:58:43 by okurache          #+#    #+#             */
/*   Updated: 2018/06/06 22:58:43 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static unsigned char	init_filler_map(t_filler_map *const map)
{
	size_t	i;

	map->raw = (char **)malloc(sizeof(char *) * map->y);
	map->dfs = (unsigned **)malloc(sizeof(unsigned *) * map->y);
	map->points = (double **)malloc(sizeof(double *) * map->y);
	if (!map->raw || !map->dfs || !map->points)
		return (1);
	i = 0;
	while (i < map->y)
	{
		map->raw[i] = (char *)malloc(sizeof(char) * (map->x + 1));
		map->dfs[i] = (unsigned *)malloc(sizeof(unsigned) * map->x);
		map->points[i] = (double *)malloc(sizeof(double) * map->x);
		if (!map->points[i] || !map->raw[i] || !map->dfs[i])
			return (1);
		++i;
	}
	return (0);
}

static unsigned char	init_filler_token(t_filler_token *const token,
	t_filler_map *const map)
{
	size_t	i;

	token->raw = (char **)malloc(sizeof(char *) * map->y);
	if (!token->raw)
		return (1);
	i = 0;
	while (i < map->y)
	{
		token->raw[i] = (char *)malloc(sizeof(char) * (map->x + 1));
		if (!(token->raw[i]))
			return (1);
		++i;
	}
	return (0);
}

static unsigned char	read_raw_map(t_fd_reader *const sin,
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

static unsigned char	read_raw_token(t_fd_reader *const sin,
	t_filler_token *const token)
{
	char 	dummy_buffer[5];
	size_t	i;

	ft_memset(dummy_buffer, 0, 5);
	sin->vt->read_line_to_array(sin, dummy_buffer, 5);
	if (!ft_strnequ(dummy_buffer, "Piece", 5))
		return (1);
	token->y = (unsigned)sin->vt->read_llint(sin);
	token->x = (unsigned)sin->vt->read_llint(sin);
	if (!(token->x) || !(token->y))
		return (1);
	sin->vt->pass_line(sin);
	i = 0;
	while (i < token->y)
	{
		sin->vt->read_line_to_array(sin, token->raw[i], token->x + 1);
		if (token->raw[i][token->x] || ft_strlen(token->raw[i]) != token->x)
			return (1);
		++i;
	}
	return (0);
}

unsigned char			filler_make_step(t_fd_reader *const sin,
	const unsigned char player_n)
{
	static t_filler_map	map = {NULL, NULL, NULL, 0, 0};
	static t_filler_token token = {NULL, 0, 0};

	if (read_raw_map(sin, &map))
		return (1);
	if (!token.raw && init_filler_token(&token, &map))
		return (1);
	if (read_raw_token(sin, &token))
		return (1);

	if (player_n)
		;
	// Check section
	printf("Map size: %u %u\n", map.y, map.x);
	for (unsigned i = 0; i < map.y; ++i) {
		for (unsigned j = 0; j < map.x; ++j)
			printf("%c", map.raw[i][j]);
		printf("\n");
	}
	printf("Token size: %u %u\n", token.y, token.x);
	for (unsigned i = 0; i < token.y; ++i) {
		for (unsigned j = 0; j < token.x; ++j)
			printf("%c", token.raw[i][j]);
		printf("\n");
	}
	// Check section ends

	return (0);
}