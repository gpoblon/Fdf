/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:55 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/25 19:24:53 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_input_to_map(t_mlx mlx, t_input *lstinput, int fd)
{
	char	*line;
	t_input	*bgn_lst;
	int		map_length;
	int		check_width;

	map_length = 0;
	bgn_lst = NULL;
	while (ft_get_next_line(fd, &line))
	{
		lstinput = ft_newlink(&bgn_lst);
		lstinput->map = ft_strsplit(line, ' ');
		lstinput->width = ft_maplen(lstinput->map);
		if (map_length == 0)
			check_width = lstinput->width;
		else if (lstinput->width != check_width)
			ft_exit("Error: input is not a square");
		lstinput = lstinput->next;
		++map_length;
	}
	lstinput = bgn_lst;
	mlx.win = mlx_new_window(mlx.mlx, TILE_S * 20 * check_width, TILE_S * 20 * map_length, "fdf");
	ft_char_to_map(mlx, lstinput, map_length);
}

t_input	*ft_newlink(t_input **lst)
{
	while (*lst)
		lst = &(*lst)->next;
	*lst = (t_input*)malloc(sizeof(**lst));
	(*lst)->map = NULL;
	(*lst)->width = 0;
	(*lst)->next = NULL;
	return (*lst);
}

void	ft_char_to_map(t_mlx mlx, t_input *lstinput, int map_length)
{
	t_coord	i;
	t_coord	p1;
	t_coord	p2;

	i.y = -1;
	while (++i.y < map_length)
	{
		i.x = -1;
		while (++i.x < lstinput->width)
		{
			p1 = ft_view(i.x, i.y - ft_atoi(lstinput->map[i.x]));
			if (i.x < lstinput->width - 1)
			{
				p2 = ft_view(i.x + 1, i.y - ft_atoi(lstinput->map[i.x + 1]));
				ft_connect_points(mlx, p1, p2);
			}
			if (i.y < map_length - 1)
			{
				p2 = ft_view(i.x, i.y + 1 - ft_atoi(lstinput->next->map[i.x]));
				ft_connect_points(mlx, p1, p2);
			}
		}
		lstinput = lstinput->next;
	}
}

t_coord	ft_view(int x, int y)
{
	t_coord	view;

	view.x = ((x) * (TILE_S / 2));
	view.y = ((x + y) * (TILE_S / 2));
	return (view);
}
