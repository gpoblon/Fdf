/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:16:34 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/25 19:35:38 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_input		*input;
	t_mlx		mlx;
	int			fd;

	if (ac > 2)
		ft_exit("Error:number of arguments");
	fd = open(av[1], O_RDONLY);
	input = (t_input*)malloc(sizeof(t_input));
	mlx.mlx = mlx_init();
	ft_input_to_map(mlx, input, fd);
	close(fd);
	mlx_loop(mlx.mlx);
}
