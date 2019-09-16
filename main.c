/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 14:34:24 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 14:34:26 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int			make_grid(t_filler *stuff)
{
	int	y;

	y = 0;
	stuff->grid = (char**)malloc(sizeof(char*) * stuff->y_di + 1);
	if (stuff->grid == NULL)
		error();
	stuff->grid[stuff->y_di] = NULL;
	while (y < stuff->y_di)
	{
		stuff->grid[y] = (char*)malloc(sizeof(char) * stuff->x_di + 1);
		if (stuff->grid[y] == NULL)
			error();
		y++;
	}
	return (1);
}

static	void		check_playernum(char *str, t_filler *stuff)
{
	if (ft_strcmp("$$$ exec p1 : [./wvan-ees.filler]", str) == 0)
	{
		stuff->my = 'O';
		stuff->en = 'X';
	}
	else if (ft_strcmp("$$$ exec p2 : [./wvan-ees.filler]", str) == 0)
	{
		stuff->my = 'X';
		stuff->en = 'O';
	}
}

static	void		get_dimensions(char *str, t_filler *stuff)
{
	int i;

	i = 8;
	while (str[i] != ' ' && str[i] != '\0')
	{
		stuff->y_di *= 10;
		stuff->y_di += str[i] - '0';
		i++;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		stuff->x_di *= 10;
		stuff->x_di += str[i] - '0';
		i++;
	}
	make_grid(stuff);
}

/*
*** This program reads input given by the provide VM from the standard input.
*** The input is obtained using the function "get_next_line()".
*** The main uses the input to obtain player number (1 or 2) and board dimensions.
*** It then calls the function filler which handles the playing of different turns by player 1 and 2.
 */

int					main(void)
{
	t_filler	*stuff;
	t_piece		*piece;
	char		*str;

	piece = (t_piece*)malloc(sizeof(t_piece));
	stuff = (t_filler*)malloc(sizeof(t_filler));
	stuff->x_di = 0;
	stuff->y_di = 0;
	stuff->start = 0;
	stuff->t_fd = 0;
	initialize(piece, stuff);
	get_next_line(stuff->t_fd, &str);
	check_playernum(str, stuff);
	free(str);
	get_next_line(stuff->t_fd, &str);
	get_dimensions(str, stuff);
	free(str);
	filler(stuff, piece);
	free(piece);
	free(stuff);
	return (0);
}
