/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:26:09 by okurache          #+#    #+#             */
/*   Updated: 2018/06/06 16:26:09 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	Reads data from standard input (sin) and returns number of player you play
**	(1 or 2), or 0 is case of error (reading failure)
*/

static unsigned char	read_player_number(t_fd_reader *const sin)
{
	char			*line1;
	unsigned char	player_number;
	const char 		expected_line[] = "$$$ exec p";

	line1 = sin->vt->read_line(sin);
	if (!line1)
		return (0);
	if (ft_strlen(line1) < 11 || !ft_strnequ(line1, expected_line, 10))
		player_number = 0;
	else
	{
		if (line1[10] == '1')
			player_number = 1;
		else if (line1[10] == '2')
			player_number = 2;
		else
			player_number = 0;
	}
	free(line1);
	return (player_number);
}

int main(void)
{
    t_fd_reader		*sin;
	unsigned char	player_n;

	sin = new_fd_reader(0, 2048);
	if (!sin)
	{
		perror("malloc failed");
		return (0);
	}
	player_n = read_player_number(sin);
	if (player_n == 0)
	{
		perror("bad VM");
		return (0);
	}
	ft_printf("debug: player number %d\n", player_n);

	ft_printf("Unfinished!\n");
	sin->vt->del(&sin);
	return (0);
}