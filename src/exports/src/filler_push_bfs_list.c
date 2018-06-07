/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_push_bfs_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 05:09:27 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 05:09:27 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	filler_push_bfs_list(t_bfs_list *const list, const unsigned x,
	const unsigned y, const unsigned mark)
{
	list->x[list->first] = x;
	list->y[list->first] = y;
	list->mark[list->first] = mark;
	++(list->first);
}