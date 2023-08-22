/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:54:26 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 11:20:14 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"

# define KEY_ESC 65307
# define TILE_SIZE 32
# define KEY_W 119
# define KEY_D 100
# define KEY_A 97
# define KEY_S 115

typedef struct s_MapElementNode
{
	char					element;
	int						x;
	int						y;
	int						is_collectible;
	struct s_MapElementNode	*next;
}	t_map_element_node;

typedef struct s_map
{
	t_map_element_node		*elements;
	int						width;
	int						height;
	int						move_count;
	int						collectible_num;
}	t_map;

typedef struct s_images
{
	char					character;
	void					*image;
}	t_images;

typedef struct s_vars
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_map					*game_map;
	t_images				*images;
}	t_vars;

typedef struct s_position
{
	int						x;
	int						y;
}	t_position;

t_map_element_node	*insert_new_node(t_map_element_node *head,
						t_map_element_node *new_node);
t_map_element_node	*load_map_from_file(const char *map_file,
						t_vars *vars);
t_map_element_node	*add_element_to_list(t_map_element_node *head,
						char element, int x, int y);
t_map_element_node	*find_player_node(t_map_element_node *head);
t_map_element_node	*get_node_at_position(t_map_element_node *head,
						int x, int y);
t_map_element_node	*get_exit_node(t_map_element_node *head);

t_images			*init_graphics(t_vars *vars, char *title, char *map_file);
int					key_press(int keycode, t_vars *vars); // key_events.c
void				read_map(char *file_name);
char				*ft_read_left_line(int fd, char *schar);
char				*get_next_line(int fd);
char				*ft_get_line(char *schar);
char				*ft_new_line(char *schar);
void				check_exit(t_vars *vars); // actions.c
void				activate_exit(t_vars *vars); // actions.c
void				cleanup(t_vars *vars); // actions.c
void				load_images(t_images images[], void *mlx_ptr,
						int *width, int *height);

void				refresh_map(t_map_element_node *head,
						t_images images[], void *mlx_ptr, void *win_ptr);
t_map				init_map(t_map_element_node *head,
						int map_width, int map_height);
void				draw_map_elements(char *line, int y, t_vars *vars);
int					exit_ok(t_map_element_node *head);
void				process_map_line(char *line, int y, t_vars *vars);
void				process_map_file(int fd, t_vars *vars); // map_loader.c
void				validate_map_character(char character); // actions.c

void				initialize_new_node(t_map_element_node *new_node,
						char element, int x, int y); // map_operations.c
void				move_character_up(t_vars *vars); // moves_utils.c
void				move_character_down(t_vars *vars); // moves_utils.c
void				move_character_right(t_vars *vars); // moves_utils.c
void				move_character_left(t_vars *vars); // moves_utils.c
void				move_character(t_vars *vars, int dx, int dy,
						int image_index);
void				handle_move(t_vars *vars, t_map_element_node *player_node,
						t_map_element_node *destination_node, int image_index);
void				perform_right_move(t_vars *vars);
void				perform_left_move(t_vars *vars);
void				perform_up_move(t_vars *vars);
void				perform_down_move(t_vars *vars);
int					check_images(t_images *images); // main_utils.c
int					check_head(t_vars *vars);
int					check_arguments(int ac); // main_utils.c
int					validate_and_run_game(t_vars *vars); // main_utils.c
int					check_vars(t_vars *vars);
int					is_accessible(t_vars *vars); // flood_fill.c

void				measure_line_and_count(int *width, int *height, char *line);
void				measure_map_size(const char *map_file, int *map_width,
						int *map_height);
int					validate_walls(t_vars *vars); // validate_maps.c
int					validate_columns(t_vars *vars); // validate_maps.c
int					validate_rows(t_vars *vars); // validate_maps.c
int					validate_player_and_exit(t_vars *vars); // validate_maps.c
int					validate_map(t_vars *vars); // validate_maps.c
int					is_valid_character(char c); // size_map.c
int					close_program(void *param); // functions_ber.c
int					check_vars(t_vars *vars);
void				check_and_activate_exit(t_map_element_node *elements);
void				cleanup_images(t_images images[], void *mlx_ptr);
int					count_collectibles(t_map_element_node *elements);
void				result_null(t_vars *vars); // graphics_utils.c
t_map				*allocate_game_map(void);
void				display_move_count(t_vars *vars);

#endif
