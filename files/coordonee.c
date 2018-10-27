/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coordonee.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:17 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:54:17 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_etri		*ft_up_coord(t_etri *tetris, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	i = 0;
	xmin = 600;
	ymin = 600;
	while (i < 4)
	{
		if (tetris->x[i] < xmin)
			xmin = tetris->x[i];
		if (tetris->y[i] < ymin)
			ymin = tetris->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		tetris->x[i] = tetris->x[i] - xmin + x;
		tetris->y[i] = tetris->y[i] - ymin + y;
		i++;
	}
	return (tetris);
}

t_etri		*ft_tetri_coord(t_etri *tetris, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				tetris->x[i] = x;
				tetris->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (tetris);
}

t_etri		*ft_init_coord(t_etri *tetris)
{
	t_etri	*tmp;

	tmp = tetris;
	while (tetris->next)
	{
		tetris = ft_tetri_coord(tetris, ft_strsplit(tetris->str, '\n'));
		free(tetris->str);
		tetris = tetris->next;
	}
	return (tmp);
}
