/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:30:03 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/25 19:44:35 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

// void	ft_connect_points(t_mlx mlx, t_coord p1, t_coord p2)
// {
// 	int		pixel;
// 	t_algo	*math;
//
// 	math = (t_algo*)malloc(sizeof(t_algo));
// 	ft_assign_values(math, p1, p2);
// 	mlx_pixel_put(mlx.mlx, mlx.win, math->i.x, math->i.y, 0x00FFFFFF);
// 	if (math->d.x > math->d.y)
// 	{
// 	    math->cumul = math->d.x / 2;
// 		pixel = 0;
// 	    while (++pixel <= math->d.x)
// 		{
// 			math->i.x += math->step.x;
// 			math->cumul += math->d.y;
// 			if (math->cumul >= math->d.x)
// 			{
// 		    	math->cumul -= math->d.x;
// 	    		math->i.y += math->step.y;
// 			}
// 			mlx_pixel_put(mlx.mlx, mlx.win, math->i.x, math->i.y, 0x00FFFFFF);
// 	 	}
// 	}
//     else
// 	{
//     	math->cumul = math->d.y / 2;
// 		pixel = 0;
// 		while (++pixel <= math->d.y)
// 		{
//     		math->i.y += math->step.y;
//     		math->cumul += math->d.x;
//     		if ( math->cumul >= math->d.y)
// 			{
//         		math->cumul -= math->d.y;
//         		math->i.x += math->step.x;
// 			}
//     	mlx_pixel_put(mlx.mlx, mlx.win, math->i.x, math->i.y, 0x00FFFFFF);
// 		}
// 	}
// }

int		ft_connect_points(t_mlx mlx, t_coord p1, t_coord p2)
{
	t_algo		math;
	math.delta.x = ft_abs(p2.x - p1.x);
	math.delta.y = -ft_abs(p2.y - p1.y);
	math.step.x = (p1.x < p2.x) ? 1 : -1;
	math.step.y = (p1.y < p2.y) ? 1 : -1;
	math.err_1 = math.delta.x + math.delta.y;
	while(1)
	{
		mlx_pixel_put(mlx.mlx, mlx.win, p1.x, p1.y, 0x00FF0000);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		math.err_2 = math.err_1 * 2;
		if (math.err_2 <= math.delta.x)
		{
			math.err_1 += math.delta.x;
			p1.y += math.step.y;
		}
		if (math.err_2 >= math.delta.y)
		{
			math.err_1 += math.delta.y;
			p1.x += math.step.x;
		}
	}
	return (0);
}

// void	ft_assign_values(t_algo *math, t_coord p1, t_coord p2)
// {
// 	math->i.x = p1.x * TILE_S;
// 	math->i.y = p1.y * TILE_S;
// 	math->d.x = p2.x * TILE_S - p1.x * TILE_S;
// 	math->d.y = p2.y * TILE_S - p1.y * TILE_S;
// 	math->step.x = (math->d.x > 0) ? 1 : -1;
// 	math->step.y = (math->d.y > 0) ? 1 : -1;
// 	math->d.x = (math->d.x < 0) ? - math->d.x : math->d.x;
// 	math->d.y = (math->d.y < 0) ? - math->d.y : math->d.y;
// }
