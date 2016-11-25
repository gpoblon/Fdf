/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:50:10 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/25 19:16:59 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define 				TILE_S 10

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct			s_input_lst
{
	char				**map;
	int					width;
	struct s_input_lst	*next;
}						t_input;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_algorithm
{
	t_coord				delta;
	t_coord				step;
	int					err_1;
	int					err_2;
}						t_algo;

void					ft_input_to_map(t_mlx mlx, t_input *lstinput, int fd);
t_input					*ft_newlink(t_input **lst);
int						ft_maplen(char **map);
void					ft_char_to_map(t_mlx mlx, t_input *lstinput, int map_length);
t_coord					ft_view(int x, int y);
int						ft_connect_points(t_mlx mlx, t_coord p1, t_coord p2);

void					ft_assign_values(t_algo *math, t_coord p1, t_coord p2);


#endif
