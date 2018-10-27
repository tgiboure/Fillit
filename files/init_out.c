/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_out.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:13 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:54:14 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			ft_max(t_etri *tetris)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (tetris->next && i++)
		tetris = tetris->next;
	while (max * max < i * 4)
		max++;
	return (max);
}

t_etri		*ft_tetris_init(char **str, int len)
{
	t_etri	*tetris;
	int		j;
	t_etri	*tmp;

	j = 0;
	len = len == 0 ? 1 : len;
	if (!(tetris = (t_etri *)malloc(sizeof(t_etri))))
		return (NULL);
	tmp = tetris;
	while (len--)
	{
		tmp->str = str[j];
		tmp->str[20] = '\0';
		tmp->c = j + 'A';
		if (!(tmp->next = (t_etri *)malloc(sizeof(t_etri))))
			return (NULL);
		tmp = tmp->next;
		j++;
	}
	tmp->next = NULL;
	return (tetris);
}

char		**ft_fill_empty(char **tab, int max)
{
	int		x;
	int		y;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}
