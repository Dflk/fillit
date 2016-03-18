/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <rbaran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:50:51 by rbaran            #+#    #+#             */
/*   Updated: 2016/02/09 21:58:55 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	length;
	char			*str;

	if (!s)
		return ((char *)s);
	length = ft_strlen(s);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	if (str)
		str = ft_strcpy(str, s);
	return (str);
}
