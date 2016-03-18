/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:04:50 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/10 13:51:14 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int				g_map_size;

static void		ft_deletemap(t_ui *map, t_tetri *tetrimos)
{
	int		i;

	i = 0;
	while (i < g_map_size)
	{
		map[i] ^= tetrimos->content[i];
		i++;
	}
}

static void		ft_insertmap(t_ui *map, t_tetri *tetrimos)
{
	int		i;

	i = 0;
	while (i < g_map_size)
	{
		map[i] |= tetrimos->content[i];
		i++;
	}
}

static int		ft_checkmap(t_ui *map, t_tetri *tetrimos)
{
	int				i;

	i = 0;
	while (i < g_map_size)
	{
		if ((tetrimos->content[i] & map[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int				ft_resolvemap(t_ui *map, t_tetri *tetrimos)
{
	int		res;

	res = 1;
	while (ft_checkmap(map, tetrimos) == 0 && res != 0)
		res = ft_movebits_forward(tetrimos);
	if (res == 0)
	{
		ft_resetbits(tetrimos, UP);
		return (res);
	}
	ft_insertmap(map, tetrimos);
	while (tetrimos->next && !(res = ft_resolvemap(map, tetrimos->next)))
	{
		ft_deletemap(map, tetrimos);
		res = ft_movebits_forward(tetrimos);
		while (ft_checkmap(map, tetrimos) == 0 && res != 0)
			res = ft_movebits_forward(tetrimos);
		if (res == 0)
		{
			ft_resetbits(tetrimos, UP);
			return (res);
		}
		ft_insertmap(map, tetrimos);
	}
	return (1);
}
