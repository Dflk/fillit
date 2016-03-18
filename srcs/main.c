/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:45:21 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/16 16:35:44 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		g_map_size;

void	ft_check_map_size(t_tetri *tetri)
{
	int		y;
	int		i;
	int		j;

	while (tetri && (g_map_size < 4))
	{
		y = 0;
		i = -1;
		while (++i < 4)
		{
			j = 32;
			if (tetri->content[i] != 0)
				y++;
			while (--j >= 28)
				if (CHECK_BIT(tetri->content[i], j) && (32 - j) > g_map_size)
					g_map_size = 32 - j;
		}
		if (y > g_map_size)
			g_map_size = y;
		tetri = tetri->next;
	}
}

int		main(int argc, char **argv)
{
	t_tetri			*tetrimos;
	t_ui			*map;

	if (argc != 2)
		ft_error(USAGE);
	if ((tetrimos = ft_open(argv[1])))
	{
		ft_check_map_size(tetrimos);
		if ((map = (t_ui*)ft_memalloc(sizeof(int) * g_map_size)))
		{
			while (!(ft_resolvemap(map, tetrimos)) && map)
			{
				free(map);
				g_map_size++;
				map = (t_ui*)ft_memalloc(sizeof(int) * g_map_size);
				ft_reinittetri(tetrimos);
			}
			free(map);
			ft_printmap(tetrimos);
		}
		ft_freetetri(tetrimos);
	}
	return (0);
}
