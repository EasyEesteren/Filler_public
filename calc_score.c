/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_score.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 17:25:32 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 17:25:34 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			calc_score(t_filler *stuff, int **heat_map)
{
	int			y;
	int			x;
	int			score;

	score = 0;
	y = 0;
	while (y < stuff->y_di)
	{
		x = 0;
		while (x < stuff->x_di)
		{
			if (heat_map[y][x] > 0)
				score += heat_map[y][x];
			x++;
		}
		y++;
	}
	return (score);
}
