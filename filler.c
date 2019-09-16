/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 15:14:52 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 15:14:54 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
*** Fills the 2d array created to store the piece with the piece given as input
 */

static	int			fill_piece(t_piece *piece, int fd)
{
	int		i;
	char	*str;

	while (piece->ycnt < piece->y)
	{
		if (!(get_next_line(fd, &str)))
			exit(1);
		i = 0;
		while (str[i])
		{
			piece->piece[piece->ycnt][i] = str[i];
			i++;
		}
		piece->piece[piece->ycnt][i] = '\n';
		piece->piece[piece->ycnt][i + 1] = '\0';
		piece->ycnt++;
		free(str);
	}
	return (1);
}

/*
*** Allocates the necessary memory for 2d array which will contain the piece to be placed
 */

static	int			make_piece(t_piece *piece)
{
	int		y;

	y = 0;
	piece->piece = (char**)malloc(sizeof(char*) * piece->y + 1);
	if (piece->piece == NULL)
		error();
	piece->piece[piece->y] = NULL;
	while (y < piece->y)
	{
		piece->piece[y] = (char*)malloc(sizeof(char) * piece->x + 1);
		if (piece->piece[y] == NULL)
			error();
		y++;
	}
	return (1);
}

/*
*** Saves the x & y dimensions of the piece given as input with each new round. 
*** These dimensions are later used to size the piece.
 */

static	void		size_piece(t_piece *piece, int fd)
{
	int		i;
	char	*str;

	i = 6;
	if (!(get_next_line(fd, &str)))
		exit(1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		piece->y *= 10;
		piece->y += str[i] - '0';
		i++;
	}
	i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		piece->x *= 10;
		piece->x += str[i] - '0';
		i++;
	}
	free(str);
	make_piece(piece);
}

/*
*** calculates the offset of each piece if one is present
 */

static	void		calc_off(t_piece *piece)
{
	int		y;
	int		x;

	y = 0;
	piece->y_off = piece->y;
	piece->x_off = piece->x;
	while (piece->piece[y])
	{
		x = 0;
		while (piece->piece[y][x])
		{
			if (piece->piece[y][x] == '*')
			{
				if (x < piece->x_off)
					piece->x_off = x;
				if (y < piece->y_off)
					piece->y_off = y;
			}
			x++;
		}
		y++;
	}
}

/*
*** Handles the actual playing of the game. Which continues while a piece can be placed.
*** The grid is updated by fill_grid, the dimensions of the piece are obtained by size_piece
*** and used to create a 2d array which can fit the piece. 
*** The x & y co-ordinates of the best possible position (the one closest to the nearest enmey piece)
*** are given to the standard output.
 */

void				filler(t_filler *stuff, t_piece *piece)
{
	int		run;

	run = 1;
	while (run)
	{
		if (fill_grid(stuff))
		{
			size_piece(piece, stuff->t_fd);
			fill_piece(piece, stuff->t_fd);
			calc_off(piece);
			if (place(stuff, piece) < 0)
			{
				ft_printf("0 0\n");
				run = 0;
			}
			initialize(piece, stuff);
		}
	}
	free_grid(stuff->grid);
}
