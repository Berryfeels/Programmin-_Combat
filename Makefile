CC      = gcc -g
CFLAGS  = -Wall -Werror -Wextra
# Directories
SRCDIR  = src
BONUSDIR = src_bonus
OBJDIR  = obj
INCDIR  = include
MLXDIR  = minilibx
LIBFTDIR = libft

# Libraries
LIBFT    = $(LIBFTDIR)/libft.a
MLX      = $(MLXDIR)/libmlx.a
MLX_FLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lXrender -lm
LIBFT_INC = -I$(LIBFTDIR)/include
MLX_INC  = -I$(MLXDIR)

# Source Files for Main Program (src)
SRCS = \
	$(SRCDIR)/Key_handler.c \
	$(SRCDIR)/movement.c \
	$(SRCDIR)/debug.c \
	$(SRCDIR)/pars_file.c \
	$(SRCDIR)/pars_file2.c \
	$(SRCDIR)/flood_fill.c \
	$(SRCDIR)/print_error.c \
	$(SRCDIR)/flood_fill_tool.c \
	$(SRCDIR)/rays.c \
	$(SRCDIR)/free_destroy_game.c \
	$(SRCDIR)/render_ceiling_and_floor.c \
	$(SRCDIR)/initilisation.c \
	$(SRCDIR)/render_walls.c \
	$(SRCDIR)/main.c \
	$(SRCDIR)/set_game_data.c \
	$(SRCDIR)/map_accessibility_check.c \
	$(SRCDIR)/tools.c \
	$(SRCDIR)/tools2.c \
	$(SRCDIR)/map_char_check.c \
	$(SRCDIR)/validate_colors.c \
	$(SRCDIR)/map_check_tools.c \
	$(SRCDIR)/validate_elements.c \
	$(SRCDIR)/map_corner_cases.c \
	$(SRCDIR)/validate_map.c \
	$(SRCDIR)/map_empty_line_check.c \
	$(SRCDIR)/window.c \
	$(SRCDIR)/map_enclosement_check.c

# Source Files for Bonus Program (src_bonus)
BONUS_SRCS = \
	$(BONUSDIR)/ammo_bar/ammo_bar_bonus.c \
	$(BONUSDIR)/collectibe_heart/collectibe_heart_tools_bonus.c \
	$(BONUSDIR)/collectibe_heart/collectible_heart_set_bonus.c \
	$(BONUSDIR)/collectibe_heart/collectible_heart_render_bonus.c \
	$(BONUSDIR)/collectible_ammo/collectible_ammo_render_bonus.c \
	$(BONUSDIR)/collectible_ammo/collectible_ammo_set_bonus.c \
	$(BONUSDIR)/collectible_ammo/collectible_ammo_tools_bonus.c \
	$(BONUSDIR)/collectible_key/collectibe_key_set_bonus.c \
	$(BONUSDIR)/collectible_key/collectible_key_render_bonus.c \
	$(BONUSDIR)/collectible_key/collectible_key_tools_bonus.c \
	$(BONUSDIR)/door/door_tools_bonus.c \
	$(BONUSDIR)/door/set_doors_data_bonus.c \
	$(BONUSDIR)/door/update_door_state_bonus.c \
	$(BONUSDIR)/free_game/free_destroy_game_bonus.c \
	$(BONUSDIR)/free_game/free_tex_path_bonus.c \
	$(BONUSDIR)/free_game/free_mlx_bonus.c \
	$(BONUSDIR)/gun/gun_bonus.c \
	$(BONUSDIR)/gun/shooting_effect_bonus.c \
	$(BONUSDIR)/health_bar/health_bar_bonus.c \
	$(BONUSDIR)/init/init_c_ammo_heart_key_bonus.c \
	$(BONUSDIR)/init/init_game_payer_minimap_colors_bonus.c \
	$(BONUSDIR)/init/init_gun_ray_health_ammo_bar_bonus.c \
	$(BONUSDIR)/init/init_textures_bonus.c \
	$(BONUSDIR)/keyboard_and_mouse/Key_handler_bonus.c \
	$(BONUSDIR)/map_checks/flood_fill_bonus.c \
	$(BONUSDIR)/map_checks/flood_fill_tool_bonus.c \
	$(BONUSDIR)/map_checks/map_accessibility_check_bonus.c \
	$(BONUSDIR)/map_checks/map_char_check_bonus.c \
	$(BONUSDIR)/map_checks/map_check_tools_bonus.c \
	$(BONUSDIR)/map_checks/map_corner_cases_bonus.c \
	$(BONUSDIR)/map_checks/map_empty_line_check_bonus.c \
	$(BONUSDIR)/map_checks/map_enclosement_check_bonus.c \
	$(BONUSDIR)/map_checks/validate_map_bonus.c \
	$(BONUSDIR)/minimap/minimap_viewangel_bonus.c \
	$(BONUSDIR)/minimap/minimap_bonus.c \
	$(BONUSDIR)/minimap/minimap_player_bonus.c \
	$(BONUSDIR)/movement/movement_bonus.c \
	$(BONUSDIR)/parsing/check_tex_path_bonus.c \
	$(BONUSDIR)/parsing/parse_file_bonus.c \
	$(BONUSDIR)/parsing/parse_line1_bonus.c \
	$(BONUSDIR)/parsing/parse_line2_bonus.c \
	$(BONUSDIR)/parsing/parse_line3_bonus.c \
	$(BONUSDIR)/ray_casting/door_dda_bonus.c \
	$(BONUSDIR)/ray_casting/rays_bonus.c \
	$(BONUSDIR)/ray_casting/render_walls_bonus.c \
	$(BONUSDIR)/render_order_bonus/render_order_bonus.c \
	$(BONUSDIR)/render_order_bonus/store_objects_in_array_bonus.c \
	$(BONUSDIR)/set_game_data/set_game_data2_bonus.c \
	$(BONUSDIR)/set_game_data/set_game_data_bonus.c \
	$(BONUSDIR)/set_game_data/set_mlx_tex_bonus.c \
	$(BONUSDIR)/sky_and_floor/render_ceiling_and_floor_bonus.c \
	$(BONUSDIR)/sky_and_floor/render_ceiling_bonus.c \
	$(BONUSDIR)/sky_and_floor/render_floor_bonus.c \
	$(BONUSDIR)/sky_and_floor/render_sky_bonus.c \
	$(BONUSDIR)/sky_and_floor/validate_colors_bonus.c \
	$(BONUSDIR)/sprite/kill_sprite_bonus.c \
	$(BONUSDIR)/sprite/move_sprite_bonus.c \
	$(BONUSDIR)/sprite/move_sprite_tools_bonus.c \
	$(BONUSDIR)/sprite/render_sprite_bonus.c \
	$(BONUSDIR)/sprite/render_sprite_tool_bonus.c \
	$(BONUSDIR)/sprite/set_sprites_bonus.c \
	$(BONUSDIR)/other/print_error_bonus.c \
	$(BONUSDIR)/other/window_bonus.c \
	$(BONUSDIR)/other/debug_bonus.c \
	$(BONUSDIR)/other/tools_bonus.c \
	$(BONUSDIR)/other/tools2_bonus.c \
	$(BONUSDIR)/other/validate_elements_bonus.c \
	$(BONUSDIR)/other/validate_objetcs_path_bonus.c \
	$(BONUSDIR)/other/validate_texture_path_bonus.c \
	$(BONUSDIR)/other/map_select_bonus.c \
	$(BONUSDIR)/other/main_bonus.c

# Object Files for Main Program (src)
OBJS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Object Files for Bonus Program (src_bonus)
BONUS_OBJS := $(patsubst $(BONUSDIR)/%.c, $(OBJDIR)/%.o, $(BONUS_SRCS))

# Output program names
NAME = cub3D
BONUS_NAME = cub3D_bonus

# Rules

normal: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

all: $(LIBFT) $(MLX) $(NAME) $(BONUS_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(MLX):
	@chmod +x $(MLXDIR)/configure
	@$(MAKE) -C $(MLXDIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

# Compilation rule (creates obj/ if needed)
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)  # Ensures the directory exists
	$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFT_INC) $(MLX_INC) -c $< -o $@

$(OBJDIR)/%.o: $(BONUSDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)  # Ensures the directory exists
	$(CC) $(CFLAGS) -I$(INCDIR) $(LIBFT_INC) $(MLX_INC) -c $< -o $@

# Ensure obj/ exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean normal

bonus_re: fclean bonus

.PHONY: all bonus clean fclean re bonus re
