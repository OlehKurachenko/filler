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

static unsigned char	read_raw_token(t_fd_reader *const sin,
	t_filler_token *const token, t_filler_map *const map)
{
	char	dummy_buffer[5];
	size_t	i;

	ft_memset(dummy_buffer, 0, 5);
	sin->vt->read_line_to_array(sin, dummy_buffer, 5);
	if (!ft_strnequ(dummy_buffer, "Piece", 5))
		return (1);
	token->y = (unsigned)sin->vt->read_llint(sin);
	token->x = (unsigned)sin->vt->read_llint(sin);
	if (!(token->x) || !(token->y) || token->x > map->x || token->y > map->y)
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

static unsigned char	check_map(t_filler_map *const map)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			map->raw[i][j] = (map->raw[i][j] == 'x') ? 'X' : map->raw[i][j];
			map->raw[i][j] = (map->raw[i][j] == 'o') ? 'O' : map->raw[i][j];
			if (!(map->raw[i][j] == '.' || map->raw[i][j] == 'O'
					|| map->raw[i][j] == 'X'))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

static unsigned char	check_token(t_filler_token *const token)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < token->y)
	{
		j = 0;
		while (j < token->x)
		{
			if (!(token->raw[i][j] == '.' || token->raw[i][j] == '*'))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

unsigned char			filler_make_step(t_fd_reader *const sin,
	const unsigned char player_n)
{
	static t_filler_map		map = {NULL, NULL, NULL, 0, 0, 0, 0};
	static t_filler_token	token = {NULL, 0, 0};

	map.my_char = (player_n == 1) ? 'O' : 'X';
	map.op_char = (player_n == 1) ? 'X' : 'O';
	if (filler_read_raw_map(sin, &map))
		return (1);
	if (!token.raw && init_filler_token(&token, &map))
		return (1);
	if (read_raw_token(sin, &token, &map))
		return (1);
	if (check_map(&map) || check_token(&token))
		return (1);
	if (filler_mark_map(&map))
		return (1);
	filler_print_best_position(&map, &token, -1, 0);
	return (0);
}
