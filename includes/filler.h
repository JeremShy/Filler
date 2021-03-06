#ifndef FILLER_H
# define FILLER_H

# include <libft.h>
# include <stdio.h>
# include <limits.h>

enum			e_flag
{
	state_first_line,
	state_board,
	state_piece
};

typedef struct	s_p
{
	struct s_p	*next;
	int			distance;
	int			x;
	int			y;
}				t_p;

typedef struct	s_vec
{
	float	x;
	float	y;
}				t_vec;

typedef struct	s_d
{
	int		player_number;
	char	enemy_char;
	char	ally_char;

	int		size_x;
	int		size_y;
	int		piece_x;
	int		piece_y;
	char	**board;
	char	**piece;
	char	*av;
	t_p		*points;
	t_p		*enemy_points;
	int		first_round;
	t_p		enemy_starting_point;
	t_p		ally_starting_point;
	t_p		target;
	int		strategy;
	int		nbr_tours;
	int		touched_enemy;
}				t_d;

typedef struct	s_gen
{
	struct s_gen	*next;
}				t_gen;

typedef int		(*t_func)(void *a, void *b);

int				parse_first_line(char *line, char *av);
int				parse_board(char *line, t_d *data);
int				parse_piece(char *line, t_d *data);
int				cmp(char *line, int *i, char c);

int				delboard(t_d *data);
int				delpiece(t_d *data);
void			dellist(t_p **list);
int				par(int ret, char *str);

void			*insert_sort(void *list, t_func comp);
int				func(void *a, void *b);

void			print_board(char **board);
void			print_list(t_p *list);
void			print_board_with_piece(t_d *data, int x, int y);
void			print_piece(char **piece);

int				is_possible(t_d *data, int x, int y);

t_p				*list_possible_pieces(t_d *data);

int				calculate_distance_piece(t_d *data, int x, int y);
int				calculate_distance(t_p *point, t_p *target);

t_p				*create_point(int x, int y, int distance);
int				add_new_point(t_p **points, int x, int y);
void			add_point(t_p **list, t_p *point);

int				put_piece(t_d *data);

int				get_coord_board(int val, int max);

int				func_bis(void *a, void *b);
int				calculate_proximity(t_p *point, t_d *data);
int				calculate_cross(t_d *data, int x, int y);

int				calculate_proximity(t_p *point, t_d *data);

int				parse_2(t_d *data);
int				parse_board_line(char *line, t_d *data);
int				parse_board_other(t_d *data);

#endif
