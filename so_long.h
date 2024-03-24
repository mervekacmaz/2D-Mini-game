#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "libs/libft/libft.h" 
#include "libs/mlx/mlx.h"
#include "libs/get_next_line/get_next_line.h"


typedef struct s_data
{
	int player_moves;

}t_data;

typedef	struct s_map
{
	char *chosen_map;
	char **map;
	int	map_height;
	int map_width;
	int collected;
	int to_collect;
	int	current_x;
	int current_y;
} t_map;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;

}t_mlx;

int		map_lenght(t_map call_map);
void	render_map(t_map call_map, t_mlx *call_mlx);
void	read_map(char *argv, t_mlx *call_mlx);
void    move_up(t_map call_map);
void    move_left(t_map call_map);

//int	get_line_count(t_map call_map);
//int	get_line_size(t_map call_map);

#endif