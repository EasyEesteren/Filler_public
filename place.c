/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 15:41:08 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 15:41:11 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void		del_lst(t_good *pos)
{
	t_good	*tmp;
	t_good	*next;

	tmp = pos;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

static int			highscore(t_good *pos)
{
	int			score_max;
	int			i;
	int			max;

	score_max = pos->score;
	max = 0;
	i = 0;
	while (pos)
	{
		if (pos->score > score_max)
		{
			score_max = pos->score;
			max = i;
		}
		i++;
		pos = pos->next;
	}
	return (max);
}

/*
*** Finds the highest score position and places its coordinates.
 */

static	void		best_pos(t_good *pos)
{
	int			i;
	int			max;

	max = highscore(pos);
	i = 0;
	while (i < max)
	{
		pos = pos->next;
		i++;
	}
	ft_printf("%i %i\n", pos->y, pos->x);
}

/*
*** Algorithm employees a heat map and linked lists to compare points.
*** Each position in the grid is checked by check_position to see if the piece can be placed there
*** If it can be placed it is saved into a linked list.
*** The heat map is then used to assign a score to each position saved in the linked list.
*** Positions closer to the enemy have a higher score. The highest score is determined by "best_pos()".
*/

int					place(t_filler *stuff, t_piece *piece)
{
	t_good *pos;

	pos = NULL;
	check_position(stuff, piece, &pos);
	if (pos == NULL)
		return (-1);
	heat_map(stuff, piece, pos);
	best_pos(pos);
	del_lst(pos);
	return (1);
}
