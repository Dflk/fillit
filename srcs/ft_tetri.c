/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:24:53 by rbaran            #+#    #+#             */
/*   Updated: 2016/03/10 14:21:15 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int				g_map_size;

static t_tetri	*ft_addtetri(char *buf, char letter)
{
	t_tetri	*tetri;
	int		i;
	int		size;

	i = -1;
	if ((tetri = (t_tetri*)ft_memalloc(sizeof(*tetri))))
	{
		if (g_map_size < 4)
			size = 4;
		else
			size = g_map_size;
		if ((tetri->content = (t_ui*)ft_memalloc(sizeof(int) * size)))
			while (++i < 20)
				if (buf[i] == '#')
					tetri->content[i / 5] += 1 << ((i % 5) + 3 - (2 * (i % 5)));
		tetri->content_size = size;
		ft_resetbits(tetri, UP);
		tetri->letter = letter;
		tetri->next = NULL;
	}
	return (tetri);
}

t_tetri			*ft_filltetri(char *buf, size_t size)
{
	t_tetri	*tetrimos;
	t_tetri	*tetrimos_buf;
	char	letter;

	tetrimos = NULL;
	letter = 'A';
	while (size > 0)
	{
		if (!tetrimos)
		{
			tetrimos = ft_addtetri(buf, letter);
			tetrimos_buf = tetrimos;
		}
		else
		{
			tetrimos_buf->next = ft_addtetri(buf, letter);
			tetrimos_buf = tetrimos_buf->next;
		}
		buf += 21;
		size--;
		letter++;
	}
	return (tetrimos);
}

void			ft_reinittetri(t_tetri *tetri)
{
	t_ui	*content_buf;

	content_buf = NULL;
	while (tetri)
	{
		ft_resetbits(tetri, UP);
		if (g_map_size > 4)
		{
			content_buf = (t_ui*)ft_memalloc(sizeof(t_tetri) * g_map_size);
			ft_memcpy(content_buf, tetri->content, sizeof(int) *
					(g_map_size - 1));
			free(tetri->content);
			tetri->content = content_buf;
			tetri->content_size++;
		}
		tetri = tetri->next;
	}
}

void			ft_freetetri(t_tetri *tetri)
{
	t_tetri	*tetri_buf;

	while (tetri)
	{
		tetri_buf = tetri;
		tetri = tetri->next;
		free(tetri_buf->content);
		free(tetri_buf);
	}
}
