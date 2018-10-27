/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:01 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:54:01 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_reset(char **tab, t_etri *tetris, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == tetris->c)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

char		**ft_save(char **tab, t_etri *tetris, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetris->x[i] == x && tetris->y[i] == y)
			{
				tab[y][x] = tetris->c;
				i++;
			}
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

int			ft_check(char **tab, t_etri *tetris, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tetris->x[i] == x && tetris->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (tetris->x[i] == x && tetris->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	return (i < 4 ? 0 : 1);
}

char		**ft_solve(char **tab, t_etri *tetris, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!tetris->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			tetris = ft_up_coord(tetris, x, y);
			if (ft_check(tab, tetris, max))
				tmp = ft_solve(ft_save(tab, tetris, max), tetris->next, max);
			if (tmp)
				return (tmp);
			tab = ft_reset(tab, tetris, max);
			x++;
		}
		y++;
	}
	return (NULL);
}

char		**ft_result(t_etri *tetris, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_fill_empty(tab, max);
		tab = ft_solve(tab, tetris, max);
		max++;
	}
	return (tab);
}
