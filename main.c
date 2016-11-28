/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:16:34 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/28 21:54:57 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_input		*input;
	t_tlkit		*tlkit;
	int			fd;

	if (ac > 2)
		ft_exit("Error:number of arguments");
	fd = open(av[1], O_RDONLY);
	input = (t_input*)malloc(sizeof(t_input));
	tlkit = (t_tlkit*)malloc(sizeof(t_tlkit));
	ft_input_to_map(tlkit, &input, fd);
	tlkit->lstinput = input;
	ft_display_map(tlkit, input);
}

void	ft_display_map(t_tlkit *tlkit, t_input *input)
{
	tlkit->mlx = mlx_init();
	tlkit->alti = 0.5;
	tlkit->zoom = 10;
	tlkit->axis_zoom.x = 1;
	tlkit->iso.x = 1;
	tlkit->iso.y = 1;
	tlkit->shift.x = 0;
	tlkit->shift.y = 0;
	tlkit->len.x = 1;
	tlkit->len.y = 1;
	tlkit->win_size.x = 1024;
	tlkit->win_size.y = 900;
	tlkit->win = mlx_new_window(tlkit->mlx, tlkit->win_size.x, tlkit->win_size.y, "fdf");
	ft_print_map(tlkit, input);
	mlx_key_hook(tlkit->win, &ft_keymap, tlkit);
	// mlx_expose_hook(tlkit->win, &ft_update_map, tlkit);
	mlx_clear_window(tlkit->mlx, tlkit->win);
	mlx_loop(tlkit->mlx);
}
