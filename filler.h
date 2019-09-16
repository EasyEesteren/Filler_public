/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 18:51:17 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 18:51:19 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./LIBFT/libft.h"

# define BUFF_SIZE 4000
# define ENDL		'\n'

typedef	struct			s_point
{
	int				y;
	int				x;
}						t_point;

typedef struct			s_good
{
	int				y;
	int				x;
	int				score;
	struct s_good	*next;
}						t_good;

typedef struct			s_piece
{
	char			**piece;
	int				x;
	int				y;
	int				x_off;
	int				y_off;
	int				ycnt;
}						t_piece;

typedef struct			s_filler
{
	char				**grid;
	t_point				target;
	t_point				start_en;
	t_point				start_my;
	t_point				*buf_my;
	t_point				*buf_en;
	int					y_di;
	int					x_di;
	int					y;
	int					start;
	int					my_cnt;
	int					en_cnt;
	char				en;
	char				my;
	int					t_fd;

}						t_filler;

int						get_next_line(const int fd, char **line);
int						fill_grid(t_filler *stuff);
int						calc_score(t_filler *stuff, int **heat_map);
int						place_around(t_filler *stuff, t_point p, \
						t_point *result);
int						place(t_filler *stuff, t_piece *piece);
int						is_o(char c);
int						is_x(char c);
void					initialize(t_piece *stuff, t_filler *grid);
void					free_grid(char **grid);
void					filler(t_filler *stuff, t_piece *piece);
void					check_position(t_filler *stuff, t_piece \
						*piece, t_good **pos);
void					error();
void					heat_map(t_filler *stuff, t_piece *piece, t_good *pos);
void					ft_freeintgrid(int **grid);
void					set_score(t_filler *stuff, int **tab_score);

#endif
