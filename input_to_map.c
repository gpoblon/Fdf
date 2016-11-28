/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:30:55 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/28 21:37:19 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_input_to_map(t_tlkit *tlkit, t_input **lstinput, int fd)
{
	char	*line;
	t_input	*bgn_lst;

	tlkit->map_length = 0;
	bgn_lst = NULL;
	while (ft_get_next_line(fd, &line))
	{
		(*lstinput) = ft_newlink(&bgn_lst);
		(*lstinput)->map = ft_strsplit(line, ' ');
		(*lstinput)->width = ft_maplen((*lstinput)->map);
		(*lstinput) = (*lstinput)->next;
		++tlkit->map_length;
	}
	(*lstinput) = bgn_lst;
	ft_char_to_int(tlkit, bgn_lst);
	close(fd);
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

	i.y = 0;
	tlkit->tab = (int**)malloc(sizeof(int*) * tlkit->map_length + 1);
	while (i.y < tlkit->map_length)
	{
		tlkit->tab[i.y] = (int*)malloc(sizeof(int) * lst->width);
		i.x = 0;
		while (i.x < lst->width)
		{
			tlkit->tab[i.y][i.x] = ft_atoi(lst->map[i.x]);
			ft_putnbr(tlkit->tab[i.y][i.x]);
			ft_putchar(' ');
			++i.x;
		}
		++i.y;
		lst = lst->next;
		ft_putchar('\n');
	}
}
