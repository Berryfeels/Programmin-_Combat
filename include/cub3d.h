#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define FOV_FACTOR 0.66

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# define SCREEN_WIDTH	800
# define SCREEN_HEIGHT	600
# define MOVE_SPEED		0.01
# define ROTATE_SPEED	0.05

//textures index
# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3

# define FLOOR	0
# define CEILING	1

//keyboard index
# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4
# define LEFT_ROTATE 5
# define RIGHT_ROTATE 6

# define KEY_W 0
# define KEY_A 1
# define KEY_S 2
# define KEY_D 3
# define KEY_RIGHT 4
# define KEY_LEFT 5

//floodfill
# define PUSH 1
# define POP 0

//Floodfill
typedef struct s_stack
{
	int	*x;
	int	*y;
	int	top;
	int	size;
}				t_stack;

//To store ceiling, sky and floor colors/textures
typedef struct s_color
{
	char	*col_tex_str;
	char	*img;
	char	*addr;
	int		r;
	int		g;
	int		b;
	int		hex_color;
	int		mode;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_color;

//Variables to render walls
typedef struct s_texture_params
{
	int		tex_x;
	double	step;
	double	tex_pos;
}			t_texture_params;

//To store walls/zombies.doors textures
typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_texture;

//Player variabels
typedef struct s_player
{
	char	*ini_dir;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		health;
	int		ammo;
	int		key;
}		t_player;

////Struct for rays
typedef struct s_ray
{
	double	camera_x;
	double	dirx;
	double	diry;
	int		mapx;
	int		mapy;
	double	side_distx;
	double	side_disty;
	double	deltadistx;
	double	deltadisty;
	double	walldist;
	int		stepx;
	int		stepy;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}				t_ray;

//Main Game Structure
typedef struct s_game
{
	int				map_started;
	int				order;
	int				duplicate;
	int				bpp;
	int				line_len;
	int				endian;
	char			**map;
	int				width;
	int				height;
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				keys[6];
	t_player		player;
	t_texture		textures[4];
	t_color			color[2];
}				t_game;

///			parsing				////
int			pars_file(const char *filename, t_game *game, char **argv);
int			assign_texture(char *line, t_game *game);
int			assign_color(char *line, t_game *game);
void		*str_start(char *str);
void		append_map_line(t_game *game, char *line);

///			validating parsed data		////
int			is_map_closed_and_accessible(t_game *game, char **map, \
										int height, int width);
int			case_one(char **map, int y, int height);
int			case_two(char **map, int y, int height);
int			case_three(char **map, int x, int height);
int			case_four(char **map, int x, int height);
int			case_five(char **map, int x, int height);
int			first_pos_row(char *line);
int			last_pos_row(char *line);
int			first_pos_col(char **map, int col);
int			last_pos_col(char **map, int col, int height);
bool		is_empty_line(const char *line);
void		remove_trailing_empty_lines(char **map);
int			check_enclosure(t_game *game, char **map);
int			validate_map_chars(t_game *game);
int			check_corners(t_game *game, char **map);
int			check_walls(t_game *game, char **map);
int			check_empty_line(char **map);
int			validate_file(const char *filename);
int			validate_cub_elements(t_game *game);
int			is_valid_texture_path(char *path);
int			validate_colors(t_color *color);
///			Floodfill 			////
void		flood_fill(t_game *game, int **visited);
void		free_visited(int **visited, int height);
int			check_accessibility(t_game *game, int **visited);
void		free_stack(t_stack *stack);
t_stack		*init_stack(int size);
void		init_directions(int *dxy);

///			init				////
void		init_ray(t_ray *ray);
void		init_mlx_ray(t_ray *ray, t_game *game, int x);
void		init_game(t_game *game);
void		init_all_mlx_textures(t_game *game);
void		init_mlx_wall_texture(t_game *game, int index, char *path);
void		load_player(t_game *game);
void		create_window(t_game *game);
int			rgb_to_hex(int r, int g, int b);

///			ray casting and render				////
int			render(t_game *game);
void		draw_floor_and_ceiling(t_game *game);
void		my_mlx_pixel_put(t_game *game, int x, int y, int color);
int			select_texture(t_ray *ray);
void		calculate_step(t_ray *ray, t_game *game);
void		calculate_wall_height(t_ray *ray);
void		perform_dda(t_ray *ray, t_game *game);
void		cast_rays(t_game *game);

///			moving			///
int			release_key(int keycode, t_game *game);
void		update_player(t_game *game);
void		rotate_player(int direction, t_game *game);
void		move_player(int direction, t_game *game);
int			press_key(int keycode, t_game *game);

///			free close game		///
int			close_window(t_game *game);
void		free_two_dim(char **arr);

///			tools				///
int			two_dim_len(char **arr);
void		cal_map_dim(t_game **game);
void		print_error(const char *format, ...);
void		print_struct(t_game *game);
long		ft_atol(const char *str);
char		*ft_strdup2(const char *s1);
int			is_all_space(const char *str);

#endif
