#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# include <sys/time.h>

# define TILE_SIZE 40
# define FOV_FACTOR 0.66

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define LIGHTBLUE 0xD8D8FF
# define LIGHTRED	0xFFBBCF
# define RESET "\033[0m"

# define SCREEN_WIDTH	1000
# define SCREEN_HEIGHT	600
# define MOVE_SPEED			0.04
# define ROTATE_SPEED	0.005
# define SKY_ROTATION_FACTOR 0.1

//Textures Index
# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3
# define ZOMBIE_0 4
# define ZOMBIE_1 5
# define ZOMBIE_2 6
# define DOOR_1	7
# define DOOR_2	8
# define DOOR_3	9
# define DOOR_4	10
# define DOOR_5	11
# define DOOR_6	12
# define FINAL_DOOR	13

# define DOOR_CLOSED 1
# define DOOR_PARTIAL 2
# define DOOR_OPEN 3

# define FLOOR	0
# define CEILING	1
# define SKY	2

# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4
# define LEFT_ROTATE 5
# define RIGHT_ROTATE 6

# define GUN 0
# define GUN_SHUT 1

//Keyboard
# define KEY_W 0
# define KEY_A 1
# define KEY_S 2
# define KEY_D 3
# define KEY_RIGHT 4
# define KEY_LEFT 5
# define KEY_SPACE 6
# define KEY_CTRL 7

//Floofill helper
# define PUSH 1
# define POP 0

//Minimap size
# define MAX_MINIMAP_WIDTH  30
# define MAX_MINIMAP_HEIGHT	15

//Rendering order
// Type: 0 = wall, 1 = sprite, 2 = heart, 3 = ammo, etc.
// Distance from player
// Pointer to the actual object (sprite, wall, etc.)
typedef struct s_renderable
{
	double	distance;
	int		type;
	void	*object;
}				t_renderable;

//Variables to draw objects
typedef struct s_draw
{
	int	screen_x;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
	int	width;
	int	height;
}				t_draw;

//Variables to draw sprites
typedef struct s_sprite_draw
{
	double	sprite_x;
	double	sprite_y;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		start_x;
	int		end_x;
	int		start_y;
	int		end_y;
	int		width;
	int		height;
}			t_sprite_draw;

//Variables to check if sprite can be killed
typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

//Floodfill
typedef struct s_stack
{
	int	*x;
	int	*y;
	int	top;
	int	size;
}				t_stack;

//Variables to render walls
typedef struct s_texture_params
{
	int		tex_x;
	double	step;
	double	tex_pos;
}			t_texture_params;

//Variables to render ceiling, sky and floor
typedef struct s_tile_coords
{
	int		x;
	int		y;
	double	tile_x;
	double	tile_y;
}				t_tile_coords;

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

//To store gun and shooting effect textures
typedef struct s_gun
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_gun;

//To store ammo bar textures
typedef struct s_ammo
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_ammo;

//To store health bar textures
typedef struct s_heath
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_health;

//To store collectible heart textures
typedef struct s_heart_tex
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_heart_tex;

//To store collectible ammo textures
typedef struct s_c_ammo_tex
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_c_ammo_tex;

//To store collectible key textures
typedef struct s_key_tex
{
	int		screen_x;
	int		screen_y;
	int		height;
	int		width;
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_key_tex;

//To store doors cordinates
//door states: open/close
typedef struct s_door
{
	int		x;
	int		y;
	int		door_state;
	long	transition_time;
	int		trigger;
	int		transition_speed;
}			t_door;

//To store sprites cordinates
typedef struct s_sprite
{
	double	x;
	double	y;
	double	distance;
	int		visible;
	double	speed;
	int		active;
	int		health;
}			t_sprite;

//To store collectible hearts cordinates
typedef struct s_heart
{
	double	x;
	double	y;
	double	distance;
	int		visible;
	int		active;
	int		animation_index;
	int		animation_timer;
	t_draw	draw;
}		t_heart;

//To store collectible ammo cordinates
typedef struct s_c_ammo
{
	double	x;
	double	y;
	double	distance;
	int		visible;
	int		active;
	int		animation_index;
	int		animation_timer;
	t_draw	draw;
}		t_c_ammo;

//to store collectible key cordinates
typedef struct s_ckey
{
	double	x;
	double	y;
	double	distance;
	int		visible;
	int		active;
	int		animation_index;
	int		animation_timer;
	t_draw	draw;
}			t_key;

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

//Struct to store minimap-related properties
typedef struct s_minimap
{
	int	tile_size;
	int	offset_x;
	int	offset_y;
	int	player_x;
	int	player_y;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
}	t_minimap;

//Struct for drawing view angel in minimap
typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	err;
	int	e2;
}	t_line;

//Struct for checking minimap bounds
typedef struct s_bounds
{
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
}		t_bounds;

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
	int		door;
	int		zombie;
	int		final_door;
}				t_ray;

typedef struct s_start_page
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				width;
	int				height;
	char			*selected_map;
}	t_start_page;

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
	int				door_count;
	int				sprite_count;
	int				heart_count;
	int				c_ammo_count;
	int				key_count;
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				keys[8];
	t_player		player;
	t_texture		textures[14];
	t_color			color[3];
	t_minimap		minimap;
	t_door			*door;
	t_ray			ray;
	t_gun			gun[2];
	t_sprite		*sprites;
	double			*z_buffer;
	t_health		health_bar[5];
	t_ammo			ammo[7];
	t_heart			*heart;
	t_heart_tex		heart_tex[12];
	t_c_ammo		*c_ammo;
	t_c_ammo_tex	c_ammo_tex[12];
	t_key			*key;
	t_key_tex		key_tex[7];
	t_start_page	*start_page;
}				t_game;

///		MLX / WINDOW / RENDER ////
void		my_mlx_pixel_put_b(t_game *game, int x, int y, int color);
void		create_window_b(t_game *game);
int			render_b(t_game *game);
void		store_objects_in_array(t_game *game, t_renderable *renderables);

///		Initiliazation ////
void		init_wall_door_textures(t_game *game);
void		init_key_tex_b(t_key_tex *key_tex, int width, int height);
void		init_game_b(t_game *game);
void		init_mlx_key_texture_b(t_game *game);
void		init_mlx_c_ammo_texture_b(t_game *game);
void		init_c_ammo_tex_b(t_c_ammo_tex *c_ammo_tex, int dim);
void		init_heart_tex_b(t_heart_tex *heart_tex, int dim);
void		init_mlx_heart_texture_b(t_game *game);
void		init_ammo_b(t_ammo *ammo, int width, int height);
void		init_mlx_ammo_bar_texture_b(t_game *game);
void		init_mlx_health_bar_texture_b(t_game *game);
void		init_health_bar_b(t_health *health_bar, int width, int height);
void		init_mlx_gun_texture_b(t_game *game, int index, char *path);
void		init_gun_b(t_gun *gun, int dim, int index);
void		init_ray_b(t_ray *ray);
void		init_mlx_wall_texture_b(t_game *game, int index, char *path);
void		init_mlx_fc_texture_b(t_game *game, int index, char *path);
void		init_mlx_ray_b(t_ray *ray, t_game *game, int x);
void		init_all_mlx_textures_b(t_game *game);
void		load_player_b(t_game *game);

///		validating Parsed data		///
int			validate_objects(t_game *game);
int			validate_ammo_paths(int start, int end, t_ammo *assets);
int			validate_c_ammo_paths(int start, int end, t_c_ammo_tex *assets);
int			validate_heart_paths(int start, int end, t_heart_tex *assets);
int			validate_health_paths(int start, int end, t_health *assets);
int			validate_key_paths(int start, int end, t_key_tex *assets);
int			validate_file_b(const char *filename);
int			validate_cub_elements_b(t_game *game);
int			is_valid_texture_path_b(char *path);
int			validate_colors_b(t_color *color);
int			is_valid_color_texture_b(t_color *color);
int			is_map_closed_and_accessible_b(t_game *game, char **map, \
				int height, int width);
int			case_one_b(char **map, int y, int height);
int			case_two_b(char **map, int y, int height);
int			case_three_b(char **map, int x, int height);
int			case_four_b(char **map, int x, int height);
int			case_five_b(char **map, int x, int height);
int			first_pos_row_b(char *line);
int			last_pos_row_b(char *line);
int			first_pos_col_b(char **map, int col);
int			last_pos_col_b(char **map, int col, int height);
bool		is_empty_line_b(const char *line);
void		remove_trailing_empty_lines_b(char **map);
int			check_enclosure_b(t_game *game, char **map);
int			validate_map_chars_b(t_game *game);
int			check_corners_b(t_game *game, char **map);
int			check_walls_b(t_game *game, char **map);
int			check_empty_line_b(char **map);
///			Floodfill 			////
void		flood_fill_b(t_game *game, int **visited);
void		free_visited_b(int **visited, int height);
int			check_accessibility_b(t_game *game, int **visited);
void		free_stack_b(t_stack *stack);
t_stack		*init_stack_b(int size);
void		init_directions_b(int *dxy);

///			Ray Casting			///
int			handle_door_hit(t_ray *ray, t_game *game);
void		calculate_wall_height_b(t_ray *ray, t_game *game, int x);
void		calculate_step_b(t_ray *ray, t_game *game);
void		perform_dda_b(t_ray *ray, t_game *game);
void		cast_rays_b(t_game *game);
int			select_texture_b(t_ray *ray, t_game *game);

///			Moving				///
int			press_key_b(int keycode, t_game *game);
void		rotate_player_b(int direction, t_game *game);
void		move_player_b(int direction, t_game *game);
int			mouse_rotate_b(int x, int y, t_game *game);
void		update_player_b(t_game *game);
int			release_key_b(int keycode, t_game *game);

///			Ceiling	| Sky | Floor	///
void		draw_floor_and_ceiling_b(t_game *game, int index);
void		draw_ceiling_texture_b(t_game *game);
void		draw_ceiling_pixel_b(t_game *game);
void		draw_floor_texture_b(t_game *game);
void		draw_floor_pixel_b(t_game *game);
void		draw_sky_texture_b(t_game *game);
int			get_cf_texture_pixel_b(t_color *color, int x, int y, int tex_id);
int			rgb_to_hex_b(int r, int g, int b);
void		set_colors_b(t_game *game, t_color *color, int index);

///			Collectible Heart	///
int			calculate_transform_heart(t_game *game, t_heart *heart, \
							double *transform_x, double *transform_y);
void		calculate_draw_positions_heart(double transform_x, \
										double transform_y, t_draw *draw);
void		render_hearts(t_game *game, t_heart *heart);
void		set_heart_cords(t_game *game);

///			Collectible Ammo 	/////
int			calculate_transform_c_ammo(t_game *game, t_c_ammo *c_ammo, \
							double *transform_x, double *transform_y);
void		calculate_draw_positions_c_ammo(double transform_x, \
										double transform_y, t_draw *draw);
void		set_c_ammo_cords(t_game *game);
void		render_c_ammo(t_game *game, t_c_ammo *c_ammo);

///			Collectibe_key			/////
int			calculate_transform_key(t_game *game, t_key *key, \
							double *transform_x, double *transform_y);
void		calculate_draw_positions_key(double transform_x, \
										double transform_y, t_draw *draw);
void		set_key_cords(t_game *game);
void		render_key(t_game *game, t_key *key);
void		key_found(t_game *game);

///			Gun			///
void		shoot_gun(t_game *game);
void		draw_gun_b(t_game *game);
void		render_gun_shut_b(t_game *game);

///			Door	///
void		door_door(t_game *game);
void		update_doors(t_game *game);
void		set_doors(t_game *game);
int			is_door_b(t_game *game);
int			which_door(t_game *game, double world_y, double world_x);
void		change_door_state(t_game *game, int index);
int			is_final_door(t_game *game);
long		get_time_of_the_day(void);

///			Mini Map	///
void		minimap_b(t_game *game);
void		draw_view_angle_b(t_game *game, int px, int py);
void		draw_player_b(t_game *game);
void		draw_tile_b(t_game *game, int x, int y, int color);
void		set_minimap_limits(t_bounds *bounds, int max_w, int max_h);

///			Parsing			///
int			pars_file_b(const char *filename, t_game *game);
int			check_line_b(char *line, t_game *game);
void		check_ammo_paths(t_game *game, int start, int end);
void		check_c_ammo_paths(t_game *game, int start, int end);
void		check_heart_paths(t_game *game, int start, int end);
void		check_health_paths(t_game *game, int start, int end);
void		check_key_paths(t_game *game, int start, int end);
int			assign_c_ammo_texture(char *line, t_game *game);
int			assign_heart_texture(char *line, t_game *game);
int			assign_ammo_texture(char *line, t_game *game);
int			assign_health_texture(char *line, t_game *game);
int			assign_texture(char *line, t_game *game);
void		append_map_line_b(t_game *game, char *line);
char		*str_start_b(char *str);
void		file_data_order_b(t_game *game);
int			assign_sprite(char *line, t_game *game);
int			assign_sky_texture(char *line, t_game *game);
int			assign_final_door_texture(char *line, t_game *game);

///			Free	//
void		free_textures_path_b(t_game *game);
void		free_mlx_b(t_game *game);
int			close_window_b(t_game *game);

///god
t_sprite	*get_zombie_in_front(t_game *game);

///			Sprite			///
int			can_move_sprite(t_game *game, double new_x, double new_y);
void		sort_sprites(t_game *game);
int			get_tex_x(t_game *game, t_sprite_draw *draw, int x, int index);
int			get_tex_y(t_game *game, t_sprite_draw *draw, int y, int index);
int			transform_sprite(t_game *game, t_sprite *sprite, \
										t_sprite_draw *draw);
void		remove_zombie(t_game *game, int index);
void		render_sprites(t_game *game, t_sprite *sprites);
void		set_sprites(t_game *game);
void		set_sprites_cords(t_game *game);
void		move_sprites(t_game *game);

///			Ammo bar	///
void		render_health_bar_b(t_game *game);
void		render_ammo_bar_b(t_game *game);

///			Tools ///
void		free_two_dim_b(char **arr);
int			two_dim_len_b(char **arr);
void		cal_map_dim_b(t_game **game);
void		print_error_b(const char *format, ...);
void		game_over(void);
void		victory(void);
long		ft_atol(const char *str);
char		*ft_strdup2(const char *s1);
int			is_all_space(const char *str);

///			Check if a collectible is collected ///
void		check_collect_key(t_game *game);
void		check_collect_ammo(t_game *game);
void		check_collect_hearts(t_game *game);
void		print_struct_b(t_game *game);

///			map selection window ///
void		start(t_start_page *start_page);

#endif
