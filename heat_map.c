/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heat_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 15:49:47 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 15:49:49 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void		init_map(t_filler *stuff, int **heat_map)
{
	int	i;

	i = 0;
	while (i < stuff->y_di)
	{
		heat_map[i] = (int*)malloc(sizeof(int) * stuff->x_di);
		i++;
	}
	heat_map[i] = NULL;
}

static void			set_empty(t_filler *stuff, int **heat_map)
{
	int			y;
	int			x;

	y = 0;
	while (y < stuff->y_di)
	{
		x = 0;
		while (x < stuff->x_di)
		{
			heat_map[y][x] = 1;
			x++;
		}
		y++;
	}
}

static void			set_piece(int **heat_map,
		t_piece *piece, t_good *pos)
{
	int			y;
	int			x;

	y = 0;
	while (y < piece->y)
	{
		x = 0;
		while (x < piece->x)
		{
			if (piece->piece[y][x] == '*')
				heat_map[pos->y + y][pos->x + x] = 2;
			x++;
		}
		y++;
	}
}

static	void		set_player(t_filler *stuff,
			int **heat_map, t_piece *piece, t_good *pos)
{
	int			y;
	int			x;

	y = 0;
	while (y < stuff->y_di)
	{
		x = 0;
		while (x < stuff->x_di)
		{
			if (is_o(stuff->grid[y][x]))
				heat_map[y][x] = (stuff->my == 'O') ? 2 : -2;
			else if (is_x(stuff->grid[y][x]))
				heat_map[y][x] = (stuff->my == 'X') ? 2 : -2;
			x++;
		}
		y++;
	}
	set_piece(heat_map, piece, pos);
}

void				heat_map(t_filler *stuff, t_piece *piece, t_good *pos)
{
	int			**heat_map;
	int			y;

	heat_map = (int**)malloc(sizeof(int*) * (stuff->y_di + 1));
	if (heat_map == NULL)
		return ;
	init_map(stuff, heat_map);
	while (pos)
	{
		set_empty(stuff, heat_map);
		set_player(stuff, heat_map, piece, pos);
		set_score(stuff, heat_map);
		pos->score = calc_score(stuff, heat_map);
		pos = pos->next;
	}
	y = 0;
	ft_freeintgrid(heat_map);
}
