/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_print_best_position.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 06:42:59 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 06:42:59 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static unsigned char	is_valid_position(t_filler_map *const map,
	t_filler_token *const token, const int add_i, const int add_j)
{
	int			i;
	int			j;
	unsigned	overlap_i;

	overlap_i = 0;
	i = 0;
	while (i < (int)token->y)
	{
		j = 0;
		while (j < (int)token->x)
		{
			if (token->raw[i][j] == '*')
			{
				if (add_i + i < 0 || add_i + i >= (int)map->y || add_j + j < 0
						|| add_j + j >= (int)map->x
						|| map->raw[i + add_i][j + add_j] == map->op_char)
					return (0);
				else if (map->raw[i + add_i][j + add_j] == map->my_char)
					++overlap_i;
			}
			++j;
		}
		++i;
	}
	return ((overlap_i == 1) ? 1 : 0);
}

static double			evaluate_position(t_filler_map *const map,
	t_filler_token *const token, const int add_i, const int add_j)
{
	int			i;
	int			j;
	double		sum;

	sum = 0;
	i = 0;
	while (i < (int)token->y)
	{
		j = 0;
		while (j < (int)token->x)
		{
			if (token->raw[i][j] == '*'
				&& map->raw[i + add_i][j + add_j] == '.')
				sum += map->points[i + add_i][j + add_j];
			++j;
		}
		++i;
	}
	return (sum);
}

/*
**	Last two parameters are dummy parameters, best point have to accept -1
*/

void					filler_print_best_position(t_filler_map *const map,
	t_filler_token *const token, double best_points, double points)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = -(token->y);
	while (++i < (int)map->y)
	{
		j = 1 - token->x;
		while (j < (int)map->x)
		{
			if (is_valid_position(map, token, i, j))
			{
				points = evaluate_position(map, token, i, j);
				if (best_points < points)
				{
					best_points = points;
					x = j;
					y = i;
				}
			}
			++j;
		}
	}
	ft_printf("%d %d\n", y, x);
}
