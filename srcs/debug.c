#include <filler.h>

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}

void	print_piece(char **piece)
{
	int	i;

	i = 0;
	while (piece[i])
	{
		ft_putendl(piece[i]);
		i++;
	}
}

void	print_list(t_p *list)
{
	printf("-------------------------\n");
	while (list)
	{
		if (list->next)
			printf("%d->", list->distance);
		else
			printf("%d\n", list->distance);
		list = list->next;
	}
}

void	print_board_with_piece(t_d *data, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < data->size_x)
	{
		j = 0;
		while (j < data->size_y)
		{
			if (j >= y && j < y + data->piece_y && i >= x && i < x + data->piece_x)
			{
				if (data->piece[i - x][j - y] == '*')
					printf("*");
				else
					printf("%c", data->board[i][j]);
			}
			else
				printf("%c", data->board[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}