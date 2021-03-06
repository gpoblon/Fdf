/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:50:10 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/30 18:56:55 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define WIN_WIDTH		1200
# define WIN_HEIGHT		1000
# define TILE_LEN		15

# define ESC			53
# define K_RIGHT		2
# define K_LEFT			0
# define K_UP			13
# define K_DOWN			1
# define K_ZOOM_IN		24
# define K_ZOOM_OUT		27
# define K_ALTI_UP		14
# define K_ALTI_DOWN	12
# define K_SPINX_1		123
# define K_SPINX_2		124
# define K_SPINY_1		126
# define K_SPINY_2		125

# define K_ISO_XP		86
# define K_ISO_XL		88
# define K_ISO_YP		91
# define K_ISO_YL		87

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_input_lst
{
	char				**map;
	int					width;
	struct s_input_lst	*next;
}						t_input;

typedef struct			s_handbag
{
	void				*mlx;
	void				*win;
	int					**tab;
	int					map_length;
	int					map_width;
	float				alti;
	int					zoom;
	t_coord				iso;
	t_coord				shift;
	t_coord				len;
	t_coord				win_size;
	t_input				*lstinput;
}						t_tlkit;

typedef struct			s_algorithm
{
	t_coord				delta;
	t_coord				step;
	int					err_1;
	int					err_2;
}						t_algo;

void					ft_input_to_map(t_tlkit *tlkit, t_input **lst, int fd);
t_input					*ft_newlink(t_input **lst);
void					ft_check_map(t_input *lst);
void					ft_char_to_int(t_tlkit *tlkit, t_input *lst);

void					ft_display_map(t_tlkit *tlkit);
void					ft_print_map(t_tlkit *tlkit, t_input *input);
t_coord					ft_view(t_tlkit *tlkit, int x, int y);
int						ft_connect_points(t_tlkit *tlkit, t_coord p1,
						t_coord p2, int color);

int						ft_keymap(int keycode, t_tlkit *tlkit);
void					ft_keymap2(int keycode, t_tlkit *tlkit);
int						ft_update_map(t_tlkit *tlkit);

#endif
