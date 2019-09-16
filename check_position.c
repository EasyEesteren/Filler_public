/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_position.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 15:48:49 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 15:48:50 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			add_pos(t_good **pos, int y, int x)
{
	t_good	*tmp;

	if (*pos == NULL)
	{
		*pos = (t_good*)malloc(sizeof(t_good));
		tmp = *pos;
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
	else
	{
		tmp = *pos;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_good*)malloc(sizeof(t_good));
		tmp = tmp->next;
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
}

static int			check_point(t_filler *stuff,
			t_point *p, t_point *ptr, int *overlaped)
{
	if (stuff->my == 'O')
	{
		if (is_o(stuff->grid[p->y + ptr->y][p->x + ptr->x]))
		{
			if (*overlaped > 0)
				return (-1);
			else
				*overlaped = 1;
		}
		else if (stuff->grid[p->y + ptr->y][p->x + ptr->x] != '.')
			return (-1);
	}
	else if (stuff->my == 'X')
	{
		if (is_x(stuff->grid[p->y + ptr->y][p->x + ptr->x]))
		{
			if (*overlaped > 0)
				return (-1);
			else
				*overlaped = 1;
		}
		else if (stuff->grid[p->y + ptr->y][p->x + ptr->x] != '.')
			return (-1);
	}
	return (1);
}

static int			verify_pos(t_filler *stuff,
			t_piece *piece, t_point *p)
{
	int			overlaped;
	t_point		ptr;

	overlaped = 0;
	ptr.y = 0;
	while (ptr.y < piece->y - piece->y_off)
	{
		ptr.x = 0;
		while (ptr.x < piece->x - piece->x_off)
		{
			if (piece->piece[ptr.y + piece->y_off][ptr.x + piece->x_off] \
			&& piece->piece[ptr.y + piece->y_off][ptr.x + piece->x_off] == '*')
			{
				if ((p->y + ptr.y >= stuff->y_di) ||
						(p->x + ptr.x >= stuff->x_di) ||
						check_point(stuff, p, &ptr, &overlaped) < 0)
					return (-1);
			}
			ptr.x++;
		}
		ptr.y++;
	}
	return ((overlaped) ? 1 : -1);
}

/*
*** Check_position goes through and checks every char in the grid for placement
*/

void				check_position(t_filler *stuff,
				t_piece *piece, t_good **pos)
{
	t_point p;

	p.y = 0;
	while (stuff->grid[p.y])
	{
		p.x = 0;
		while (stuff->grid[p.y][p.x])
		{
			if (verify_pos(stuff, piece, &p) > 0)
				add_pos(pos, p.y - piece->y_off, p.x - piece->x_off);
			p.x++;
		}
		p.y++;
	}
}
