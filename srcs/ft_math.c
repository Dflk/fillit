/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:17:49 by rbaran            #+#    #+#             */
/*   Updated: 2016/02/23 18:25:29 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <stdio.h>

int		g_map_size;

void	ft_math(int nb)
{
	int		res;
	int		odd;
	int		res_odd;
	int		nb_add;

	res = nb * 4;
	odd = 1;
	res_odd = 0;
	nb_add = 0;
	while (res_odd < res)
	{
		res_odd += odd;
		odd += 2;
		nb_add++;
	}
	g_map_size = nb_add;
}
