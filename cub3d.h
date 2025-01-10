/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <seongjko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:31:01 by seongjko          #+#    #+#             */
/*   Updated: 2024/06/27 13:55:45 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./queue.h"

# define WIDTH 1920
# define HEIGHT 1080
# define BACKWARD 1
# define FORWARD 13
# define LEFT 0
# define RIGHT 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define ESC 53
# define NEAR_ZERO 1e-9

typedef struct s_user {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}	t_user;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_map {
	int	**worldmap;
	int	map_height;
	int	map_width;
}	t_map;

typedef struct s_texture {
	void			*img;
	char			*tex_path;
	unsigned int	*tex_data;
	int				tex_height;
	int				tex_width;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}	t_texture;

typedef struct s_screen {
	t_map		worldmap;
	int			floor;
	int			ceiling;
	t_texture	tex_ary[4];
	int			**buffer;
}	t_screen;

typedef struct s_calc{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
}	t_calc;

typedef struct s_struc{
	t_user		*user;
	t_screen	*screen;
	t_mlx		*mlx;
}	t_struc;

void	init_structs(t_user *user, t_mlx *mlx, t_screen *screen);
void	init_screen(t_mlx *mlx, t_screen *screen);
void	execution_main(t_user *user, t_mlx *mlx, t_screen *screen);
void	fill_buffer(t_user *user, t_screen *screen);
void	clear_buffer(t_screen *screen);
void	init_buffer_with_zero(t_screen *screen);
void	init_vars(t_user *user, t_calc *var, int x);
void	init_step_and_sidedist(t_user *user, t_calc *var);
void	shoot_ray(t_calc *var, t_screen *screen);
void	fish_eye_correction(t_calc *var, t_user *user);
void	calc_draw_y_coordinates(t_calc *var);
void	calc_texture(t_calc *var, t_user *user, t_screen *screen, int x);
void	calc_texture_vars(t_calc *var, t_user *user, t_screen *screen);
void	calc_texture_coor(t_calc *var, t_screen *screen, int x);
void	draw_buffer(t_mlx *mlx, t_screen *screen);
void	init_tex_ary(t_mlx *mlx, t_screen *screen);
int		key_press(int key, t_struc *struc);
void	draw_floor_and_ceiling(t_calc *var, t_screen *screen, int x);
void	parsing_map(t_screen *screen, char *path);
int		exit_hook(t_mlx *mlx);
void	init_user(t_user *user, t_screen *screen);
void	init_mlx(t_mlx *mlx);
void	init_screen(t_mlx *mlx, t_screen *screen);
void	init_camera_plane(t_user *user, t_screen *screen, int y, int x);
void	set_user_vector(t_user *user, t_screen *screen, int y, int x);
void	init_deltadist(t_calc *var);
void	rotate_left(t_struc *struc);
void	rotate_right(t_struc *struc);
int		exit_hook(t_mlx *mlx);
void	draw_new_img(t_struc *struc);
int		check_texture_path(t_screen *screen);
int		is_move_possible(t_struc *struc, int new_x, int new_y);

void	_error(char *msg, int error_code);
int		check_file_name(char *path);
int		check_num(char *num);
int		free_split(char **split_res, int code);
int		color_data_extract(char *color);

int		element_to_int(char *element);
int		identifier_parsing(t_screen *screen, char *line, int *count);
void	dump_fd(int fd);
int		extract_texture(t_screen *screen, int fd_tmp, int fd_real);

int		maxi(int a, int b);
void	extract_map_size(t_map *map, int fd_tmp, int fd_real);
void	map_alloc(t_map *map);
void	extract_map(t_map *map, int fd_tmp, int fd_real);

void	flood(t_map *map, int **visited, t_queue **queue, t_pair coor);
void	bfs(t_map *map, int **visited, int y, int x);
void	visited_free(t_map *map, int **visited);
int		**visited_alloc(t_map *map);

void	check_map(t_map *map);
void	check_map_character(t_map *map);
void	parsing_map(t_screen *screen, char *path);

#endif
