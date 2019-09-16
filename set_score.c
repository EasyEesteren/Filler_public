/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_score.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 18:37:28 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 18:37:30 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_place_around(t_filler *stuff,
		int **heat_map, t_point *p, int current)
{
	int			y;
	int			x;

	y = p->y - 1;
	while (y <= p->y + 1)
	{
		x = p->x - 1;
		while (x <= p->x + 1)
		{
			if ((y >= 0 && y < stuff->y_di) && (x >= 0 && x < stuff->x_di))
			{
				if (heat_map[y][x] == 1)
					heat_map[y][x] = current + 1;
				else if (heat_map[y][x] == -current - 1)
					heat_map[y][x] = 0;
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int		ft_place_around_adv(t_filler *stuff,
		int **heat_map, t_point *p, int current)
{
	int			y;
	int			x;

	y = p->y - 1;
	while (y <= p->y + 1)
	{
		x = p->x - 1;
		while (x <= p->x + 1)
		{
			if ((y >= 0 && y < stuff->y_di) && (x >= 0 && x < stuff->x_di))
			{
				if (heat_map[y][x] == 1)
					heat_map[y][x] = -current - 1;
				else if (heat_map[y][x] == current + 1)
					heat_map[y][x] = 0;
			}
			x++;
		}
		y++;
	}
	return (1);
}

void			set_score(t_filler *stuff, int **heat_map)
{
	t_point		p;
	int			current;
	int			find;

	current = 2;
	find = 1;
	while (find == 1)
	{
		find = 0;
		p.y = 0;
		while (p.y < stuff->y_di)
		{
			p.x = 0;
			while (p.x < stuff->x_di)
			{
				if (heat_map[p.y][p.x] == current)
					find = ft_place_around(stuff, heat_map, &p, current);
				else if (heat_map[p.y][p.x] == -current)
					find = ft_place_around_adv(stuff, heat_map, &p, current);
				p.x++;
			}
			p.y++;
		}
		current++;
	}
}
