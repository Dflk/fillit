/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 15:45:39 by rbaran            #+#    #+#             */
/*   Updated: 2016/04/01 12:54:33 by rbaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <libft.h>
# define BUF_SIZE 26*21
# define USAGE 1
# define UP 1
# define DOWN 0
# define CHECK_BIT(BYTE, POS) (BYTE & (1 << POS))

typedef unsigned int	t_ui;
typedef struct			s_tetri
{
	unsigned int	*content;
	int				content_size;
	char			letter;
	struct s_tetri	*next;
}						t_tetri;
void					ft_error(int flag);
void					ft_freetetri(t_tetri *tetri);
t_tetri					*ft_open(char *file_name);
t_tetri					*ft_read(int fd);
t_tetri					*ft_filltetri(char *buf, size_t size);
void					ft_reinittetri(t_tetri *tetri);
void					ft_resetbits(t_tetri *tetri, int flag);
void					ft_printtetrimos(t_tetri *tetrimos);
int						ft_resolvemap(t_ui *map, t_tetri *tetrimos);
unsigned int			ft_movebits_forward(t_tetri *tetrimos);
void					ft_printmap(t_tetri *tetrimos);
void					ft_math(int nb);

#endif
