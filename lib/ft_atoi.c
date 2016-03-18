/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 22:11:28 by rbaran            #+#    #+#             */
/*   Updated: 2016/02/15 17:59:46 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		res;
	int		signe;

	res = 0;
	signe = 1;
	if (!nptr)
		return (res);
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\v' ||
		*nptr == '\f')
		nptr++;
	if (*nptr == '-')
		signe = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr <= '9' && *nptr >= '0')
	{
		res = (res * 10) + (*nptr - '0');
		nptr++;
	}
	return (res * signe);
}
