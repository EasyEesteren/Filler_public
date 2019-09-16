/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freeintgrid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 17:45:11 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 17:45:14 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_freeintgrid(int **grid)
{
	int	y;

	y = 0;
	while (grid[y])
	{
		free(grid[y]);
		y++;
	}
	free(grid);
}
