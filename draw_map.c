/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:30:03 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/30 18:53:29 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_tlkit *tlkit, t_input *lst)
{
	t_coord	i;
	t_coord	p1;
	t_coord	p2;

	i.y = -1;
	while (++i.y < tlkit->map_length)
	{
		i.x = -1;
		while (++i.x < lst->width)
		{
			p1 = ft_view(tlkit, i.x, i.y);
			if (i.x < lst->width - 1)
			{
				p2 = ft_view(tlkit, i.x + 1, i.y);
				ft_connect_points(tlkit, p1, p2, 15 * tlkit->tab[i.y][i.x]);
			}
			if (i.y < tlkit->map_length - 1 && i.x < lst->next->width)
			{
				p2 = ft_view(tlkit, i.x, i.y + 1);
				ft_connect_points(tlkit, p1, p2, 15 * tlkit->tab[i.y][i.x]);
			}
		}
		lst = lst->next;
	}
}

t_coord	ft_view(t_tlkit *tlkit, int x, int y)
{
	t_coord	view;

	view.x = ((x * tlkit->len.x - y * tlkit->len.y) * tlkit->zoom) *
			tlkit->iso.x + tlkit->shift.x;
	view.y = (((y - tlkit->tab[y][x] * tlkit->alti) + x) * tlkit->zoom) *
			tlkit->iso.y + tlkit->shift.y;
	return (view);
}

int		ft_connect_points(t_tlkit *tlkit, t_coord p1, t_coord p2, int color)
{
	t_algo		math;

	math.delta.x = ft_abs(p2.x - p1.x);
	math.delta.y = -ft_abs(p2.y - p1.y);
	math.step.x = (p1.x < p2.x) ? 1 : -1;
	math.step.y = (p1.y < p2.y) ? 1 : -1;
	math.err_1 = math.delta.x + math.delta.y;
	while (1)
	{
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
		mlx_pixel_put(tlkit->mlx, tlkit->win, p1.x, p1.y, color + 0x00777777);
	}
	return (0);
}
