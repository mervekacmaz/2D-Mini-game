/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:21:38 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/09/24 12:21:40 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(t_map call_map)
{
    int i;
    i = 0;
    
    while(call_map.map[i])
    {
        i++;
    }
    return i;
}

int	get_width(t_map call_map)
{
         int j = 0;
        while(call_map.map[0][j])
        {
            j++;
        }
        return j;
}

void render_map(t_map call_map, t_mlx *call_mlx)
{
    int i = 0;
    int j;
    void *wall_img;
    void *player_img;
    void *collectible_img;
    void *exit_img;
    int width;
    int height;
    int x;
    int y;

    width = 64;
    height = 64;
    x = 0;
    y = 0;
    mlx_clear_window(call_mlx->mlx, call_mlx->mlx_win);
    while(call_map.map[i])
    {
        j = 0;
        x = 0;
        while(call_map.map[i][j])
        {
           
            if(call_map.map[i][j] == '1')
            {
                wall_img = mlx_xpm_file_to_image(call_mlx->mlx, "wall.xpm", &width, &height);
                mlx_put_image_to_window(call_mlx->mlx, call_mlx->mlx_win, wall_img, x, y);
            }

            if(call_map.map[i][j] == 'P')
            {
                player_img = mlx_xpm_file_to_image(call_mlx->mlx, "player.xpm", &width, &height);
                mlx_put_image_to_window(call_mlx->mlx, call_mlx->mlx_win, player_img, x, y);
            }

            if(call_map.map[i][j] == 'C')
            {
                collectible_img = mlx_xpm_file_to_image(call_mlx->mlx, "collectible.xpm", &width, &height);
                mlx_put_image_to_window(call_mlx->mlx, call_mlx->mlx_win, collectible_img, x, y);
            }

            if(call_map.map[i][j] == 'C')
            {
                exit_img = mlx_xpm_file_to_image(call_mlx->mlx, "exit.xpm", &width, &height);
                mlx_put_image_to_window(call_mlx->mlx, call_mlx->mlx_win, exit_img, x, y);
            }

            x += width;
            j++;
        }
        y += height;
        i++;
    }
}


int map_lenght(t_map call_map)
{
    int i_read_boi;
    char c;
    int fd;

    i_read_boi = 0;
    fd = open(call_map.chosen_map, O_RDONLY);
    while(read(fd, &c, 1))
    {   
        i_read_boi++;
    }
    close(fd);
    return i_read_boi;
}

void    read_map(char *argv, t_mlx *call_mlx)
{ 
    t_map call_map;
    int len;
    char *mappy_map;
    int fd;

    call_map.chosen_map = argv;
    fd = open(call_map.chosen_map, O_RDONLY);
    len = map_lenght(call_map);
    
    mappy_map = malloc(sizeof(char) * len + 1);
    read (fd, mappy_map, len);
    mappy_map[len] = '\0';
    call_map.map = ft_split(mappy_map, '\n');

    int height = get_height(call_map);
    int width = get_width(call_map);
    call_mlx->mlx_win = mlx_new_window(call_mlx->mlx, 64 * width, 64 * height, "Game on!");
    free(mappy_map);
    render_map(call_map, call_mlx);
}

/*
void    control_map(t_map call_map)
{

}

void    player_movement(t_map *call_map, int i, int j)
{
    if (call_map->map[i][j] != '1' && call_map->map[i][j] != 'E')
        {
            if (call_map->map[i][j] == 'C' && call_map->to_collect != call_map->collected)
                call_map->collected += 1;


        }

}
*/

int    key_event(int keycode, t_map *call_map)
{
    if(keycode == 13)
    {

    }
    else if (keycode == 0)
    {
        
    }
    else if (keycode == 1)
    {
       // move_down(&call_map);
    }
    else if (keycode == 2)
    {
    //    move_right(&call_map);
    }
    printf("%d\n", keycode);
    return 0;
}

int main(int argc, char **argv)
{
	t_map call_map;
    t_mlx call_mlx;


    if(argc < 1)
        return (0);

	call_mlx.mlx = mlx_init(); //DIDNT UNDERSTAND THIS ONE??
    read_map(argv[1], &call_mlx);
    //control_map(call_map);
    mlx_hook(call_mlx.mlx_win, 2, 1L<<0, key_event, &call_map);
    mlx_loop(call_mlx.mlx);
}



