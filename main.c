/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:16:34 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/30 18:56:48 by gpoblon          ###   ########.fr       */
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
	ft_display_map(tlkit);
}

void	ft_display_map(t_tlkit *tlkit)
{
	tlkit->mlx = mlx_init();
	tlkit->alti = 1.2;
	tlkit->zoom = 5;
	tlkit->win_size.x = WIN_WIDTH + 2 * (tlkit->map_width);
	tlkit->win_size.y = WIN_HEIGHT + 2 * (tlkit->map_length);
	tlkit->iso.x = 1;
	tlkit->iso.y = 1;
	tlkit->shift.x = (tlkit->win_size.x / 2.5 - tlkit->map_width);
	tlkit->shift.y = (tlkit->win_size.y / 2.5 - tlkit->map_length);
	tlkit->len.x = 3;
	tlkit->len.y = 1;
	tlkit->win = mlx_new_window(tlkit->mlx, tlkit->win_size.x,
				tlkit->win_size.y, "fdf");
	ft_print_map(tlkit, tlkit->lstinput);
	mlx_key_hook(tlkit->win, &ft_keymap, tlkit);
	mlx_loop(tlkit->mlx);
}
