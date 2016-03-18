/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:21:36 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/10 14:20:18 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int				g_map_size;

static char		*ft_fillchar(t_tetri *tetri, t_tetri *tetri_buf, int index)
{
	int				i;
	int				j;
	char			*str;

	if ((str = (char*)ft_memalloc(sizeof(char) * (g_map_size + 1))))
	{
		str[g_map_size] = '\0';
		i = 32;
		j = 0;
		while (--i > (31 - g_map_size))
		{
			tetri = tetri_buf;
			while (tetri && (str[j] == '.' || str[j] == 0))
			{
				if (CHECK_BIT(tetri->content[index], i))
					str[j] = tetri->letter;
				else if (str[j] == 0)
					str[j] = '.';
				tetri = tetri->next;
			}
			j++;
		}
	}
	return (str);
}

void			ft_printmap(t_tetri *tetrimos)
{
	int		i;
	char	**map;

	i = -1;
	if ((map = (char**)ft_memalloc(sizeof(char*) * g_map_size)))
	{
		while (++i < g_map_size && tetrimos)
			map[i] = ft_fillchar(tetrimos, tetrimos, i);
		i = -1;
		while (++i < g_map_size)
		{
			ft_putstr(map[i]);
			ft_putchar('\n');
		}
		free(map);
	}
}
