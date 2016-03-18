/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:52:45 by rbaran            #+#    #+#             */
/*   Updated: 2016/02/26 18:32:19 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

static int			ft_checkshape(const char *buf, t_ui i, t_ui i_before)
{
	int				res;

	res = 0;
	if (*buf == '#')
	{
		res = 1;
		if ((i % 5) < 4 && (i + 1) != i_before && res != 4)
			res += ft_checkshape(buf + 1, (i + 1), i);
		if ((i % 5) > 0 && (i - 1) != i_before && res != 4)
			res += ft_checkshape(buf - 1, (i - 1), i);
		if ((i / 5) < 3 && res != 4)
			res += ft_checkshape(buf + 5, (i + 5), i);
	}
	return (res);
}

static unsigned int	ft_checkbuf(const char *buf, t_ui i_limit)
{
	unsigned int	i;
	unsigned int	blocks;
	int				shape;

	i = 0;
	blocks = 0;
	shape = -1;
	while (i <= i_limit)
	{
		if ((i + 1) % 5 != 0 && *buf != '.' && *buf != '#')
			ft_error(0);
		else if ((i + 1) % 5 == 0 && *buf != '\n')
			ft_error(0);
		if (*buf == '#')
		{
			if (shape == -1)
				shape = ft_checkshape(buf, i, i);
			blocks++;
		}
		buf++;
		i++;
	}
	if (blocks != 4 || shape != 4)
		ft_error(0);
	return (i);
}

t_tetri				*ft_read(int fd)
{
	char			buf[BUF_SIZE];
	int				ret;
	int				i;

	ret = read(fd, buf, BUF_SIZE);
	close(fd);
	if (ret == -1 || (ret % 21) == 0)
		ft_error(0);
	i = 0;
	while (i < ret)
		i += ft_checkbuf((char*)buf + i, 19) + 1;
	ft_math(ret / 20);
	return (ft_filltetri(buf, (size_t)ret / 20));
}
