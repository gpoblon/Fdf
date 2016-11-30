/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymapping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:38:11 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/30 18:27:51 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_update_map(t_tlkit *tlkit)
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
		tlkit->shift.x -= 30;
	else if (keycode == K_LEFT)
		tlkit->shift.x += 30;
	else if (keycode == K_UP)
		tlkit->shift.y += 30;
	else if (keycode == K_DOWN)
		tlkit->shift.y -= 30;
	else if (keycode == K_ZOOM_IN)
		tlkit->zoom += 1;
	else if (keycode == K_ZOOM_OUT)
		tlkit->zoom <= 1 ? tlkit->zoom = 1 : --tlkit->zoom;
	else if (keycode == K_ALTI_UP)
		tlkit->alti += 0.3;
	else if (keycode == K_ALTI_DOWN)
		tlkit->alti -= 0.3;
	ft_keymap2(keycode, tlkit);
	ft_update_map(tlkit);
	return (0);
}

void	ft_keymap2(int keycode, t_tlkit *tlkit)
{
	if (keycode == K_SPINX_1)
		tlkit->len.x <= 1 ? tlkit->len.x = 1 : --tlkit->len.x;
	else if (keycode == K_SPINX_2)
		tlkit->len.x += 1;
	else if (keycode == K_SPINY_1)
		tlkit->len.y <= 1 ? tlkit->len.y = 1 : --tlkit->len.y;
	else if (keycode == K_SPINY_2)
		tlkit->len.y += 1;
	else if (keycode == K_ISO_XP)
		tlkit->iso.x += 1;
	else if (keycode == K_ISO_YP)
		tlkit->iso.y += 1;
	else if (keycode == K_ISO_XL)
		tlkit->iso.x <= 1 ? tlkit->iso.x = 1 : --tlkit->iso.x;
	else if (keycode == K_ISO_YL)
		tlkit->iso.y <= 1 ? tlkit->iso.y = 1 : --tlkit->iso.y;
}
