/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:55 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/29 19:54:30 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_input_to_map(t_tlkit *tlkit, t_input **lstinput, int fd)
{
	char	*line;
	t_input	*bgn_lst;

	tlkit->map_length = 0;
	tlkit->map_width = 0;
	bgn_lst = NULL;
	while (ft_get_next_line(fd, &line))
	{
		(*lstinput) = ft_newlink(&bgn_lst);
		(*lstinput)->map = ft_strsplit(line, ' ');
		(*lstinput)->width = ft_maplen((*lstinput)->map);
		if ((*lstinput)->width > tlkit->map_width)
			tlkit->map_width = (*lstinput)->width;
		ft_check_map((*lstinput));
		(*lstinput) = (*lstinput)->next;
		++tlkit->map_length;
	}
	(*lstinput) = bgn_lst;
	ft_char_to_int(tlkit, bgn_lst);
	close(fd);
}

void	ft_check_map(t_input *lst)
{
	int		i;
	int		j;

	i = 0;
	while (lst->map[i])
	{
		j = 0;
		while (lst->map[i][j])
		{
			if (!ft_isdigit(lst->map[i][j]))
				ft_exit("Error: non digit character");
			++j;
		}
		++i;
	}
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

void	ft_char_to_int(t_tlkit *tlkit, t_input *lst)
{
	t_coord	i;

	i.y = -1;
	tlkit->tab = (int**)malloc(sizeof(int*) * tlkit->map_length + 1);
	while (++i.y < tlkit->map_length)
	{
		tlkit->tab[i.y] = (int*)malloc(sizeof(int) * lst->width);
		i.x = -1;
		if (tlkit->map_length > 1 && lst->width == 0)
			ft_exit("Error: empty lines.");
		while (++i.x < lst->width)
		{
			tlkit->tab[i.y][i.x] = ft_atoi(lst->map[i.x]);
			ft_putnbr(tlkit->tab[i.y][i.x]);
			ft_putchar(' ');
		}
		if (tlkit->map_length == 1 && tlkit->map_width == 0)
			ft_exit("Error: empty file.");
		if (tlkit->map_length == 1 && tlkit->map_width == 1)
			ft_exit("Error: can't wire anything with only one point.");
		lst = lst->next;
		ft_putchar('\n');
	}
}
