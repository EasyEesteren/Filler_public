/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 15:38:18 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 15:38:20 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fill_grid(t_filler *stuff)
{
	int		i;
	int		x;
	char	*str;

	while (stuff->y < stuff->y_di)
	{
		if (!(get_next_line(stuff->t_fd, &str)))
			exit(1);
		if (ft_strncmp("   ", str, 3) == 0 || \
			ft_strncmp("Plateau", str, 7) == 0)
			return (0);
		x = 0;
		i = 4;
		while (str[i])
		{
			stuff->grid[stuff->y][x] = str[i];
			x++;
			i++;
		}
		stuff->grid[stuff->y][x] = '\n';
		stuff->grid[stuff->y][x + 1] = '\0';
		free(str);
		stuff->y++;
	}
	return (1);
}
