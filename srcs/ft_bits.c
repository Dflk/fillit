/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:37:15 by rbaran            #+#    #+#             */
/*   Updated: 2016/02/26 18:27:11 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int				g_map_size;

static int		ft_checkbit(t_tetri *tetri, int limit)
{
	int		i;

	i = 0;
	while (i < tetri->content_size)
	{
		if (CHECK_BIT(tetri->content[i], limit))
			return (1);
		i++;
	}
	return (0);
}

static void		ft_moveup(t_tetri *tetri)
{
	unsigned char	tmp;
	int				i;

	tmp = 0;
	while (tetri->content[0] == 0)
	{
		i = 0;
		tmp = tetri->content[0];
		while (i < tetri->content_size - 1)
		{
			tetri->content[i] = tetri->content[i + 1];
			i++;
		}
		tetri->content[i] = tmp;
	}
}

static void		ft_movedown(t_tetri *tetri)
{
	unsigned char	tmp;
	int				i;

	i = tetri->content_size - 1;
	tmp = tetri->content[i];
	while (i > 0)
	{
		tetri->content[i] = tetri->content[i - 1];
		i--;
	}
	tetri->content[0] = tmp;
}

void			ft_resetbits(t_tetri *tetri, int flag)
{
	int		i;

	while (ft_checkbit(tetri, 31) == 0)
	{
		i = 0;
		while (i < tetri->content_size)
		{
			tetri->content[i] <<= 1;
			i++;
		}
	}
	if (flag == UP)
		ft_moveup(tetri);
	else
		ft_movedown(tetri);
}

unsigned int	ft_movebits_forward(t_tetri *tetri)
{
	int		i;

	i = 0;
	if (ft_checkbit(tetri, 31 - g_map_size + 1) == 0)
	{
		while (i < tetri->content_size)
		{
			tetri->content[i] >>= 1;
			i++;
		}
	}
	else if (tetri->content[g_map_size - 1] == 0)
		ft_resetbits(tetri, DOWN);
	else
		return (0);
	return (1);
}
