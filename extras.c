/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extras.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 17:30:29 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 17:30:32 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		initialize(t_piece *piece, t_filler *grid)
{
	piece->y = 0;
	piece->x = 0;
	piece->ycnt = 0;
	piece->x_off = 0;
	piece->y_off = 0;
	grid->y = 0;
}

void		free_grid(char **grid)
{
	int y;

	y = 0;
	while (grid[y])
	{
		free(grid[y]);
		y++;
	}
}

void		error(void)
{
	ft_printf("ERROR");
	exit(-1);
}

int			is_o(char c)
{
	if (c == 'o' || c == 'O')
		return (1);
	return (0);
}

int			is_x(char c)
{
	if (c == 'x' || c == 'X')
		return (1);
	return (0);
}
