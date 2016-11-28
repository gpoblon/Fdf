/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:38:11 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/28 21:56:46 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	ft_update_map(t_tlkit *tlkit)
{
	mlx_clear_window(tlkit->mlx, tlkit->win);
	ft_print_map(tlkit, tlkit->lstinput);
	return (0);
}

int		ft_keymap(int keycode, t_tlkit *tlkit)
{
	if (keycode == ESC)
		ft_exit("Arret du programme.");
	if (keycode == K_RIGHT)
		tlkit->shift.x += 15;
	else if (keycode == K_LEFT)
		tlkit->shift.x -= 15;
	else if (keycode == K_UP)
		tlkit->shift.y -= 15;
	else if (keycode == K_DOWN)
		tlkit->shift.y += 15;
	else if (keycode == K_ZOOM_IN)
		tlkit->zoom += 2;
	else if (keycode == K_ZOOM_OUT)
		tlkit->zoom -= 2;
	else if (keycode == K_ALTI_UP)
		tlkit->alti += 0.2;
	else if (keycode == K_ALTI_DOWN)
		tlkit->alti -= 0.2;
	else if (keycode == K_SPINX_1)
		tlkit->len.x += 1;
	else if (keycode == K_SPINX_2)
		tlkit->len.x -= 1;
	else if (keycode == K_SPINY_1)
		tlkit->len.y += 1;
	else if (keycode == K_SPINY_2)
		tlkit->len.y -= 1;
	ft_update_map(tlkit);
	return (0);
}
