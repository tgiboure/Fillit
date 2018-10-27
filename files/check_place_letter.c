/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_place_letter.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:53:14 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:53:14 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_check		*check_tetro_init(void)
{
	t_check	*check;

	if (!(check = malloc(sizeof(t_check))))
		return (NULL);
	check->l = 1;
	check->nb_dpl = 1;
	return (check);
}

int			check_tetro(char *str, int memo, int diez)
{
	t_check	*check;

	if (!(check = check_tetro_init()))
		return (0);
	while (diez != 0 && check->nb_dpl != 0)
	{
		check->nb_dpl = 0;
		check->k = memo - 1;
		while (str[++check->k] != '\n')
			if (str[check->k] == '#' && diez--)
				check->nb_dpl++;
		check->k = check->k - (check->k - memo) + 5 - 1;
		while (check->nb_dpl != 0 && diez != 0)
		{
			if (str[++check->k] == '#')
			{
				while (str[check->k - 1] == '#' && check->k--)
					check->l++;
				memo = check->k;
				break ;
			}
			check->nb_dpl--;
		}
	}
	return (diez > 0 ? 0 : check->l);
}

int			check_back_diez_point(char *str)
{
	int		i;
	int		diez;
	int		memo;

	i = -1;
	diez = 0;
	memo = -1;
	if (ft_strstr(str, "#.#") || ft_strstr(str, "#..#"))
		return (0);
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n'
			|| str[20] != '\0')
		return (0);
	while (str[++i])
	{
		if (memo == -1 && str[i] == '#')
			memo = i;
		if ((str[i] != '.') && (str[i] != '#') && (str[i] != '\n'))
			return (0);
		if (str[i] == '#')
			diez++;
	}
	if (diez != 4)
		return (0);
	i = check_tetro(str, memo, diez);
	return (i);
}

t_check		*check_init(int nb_tetro)
{
	t_check	*check;

	if (!(check = malloc(sizeof(t_check))))
		return (NULL);
	if (!(check->buf = malloc(sizeof(char *) * (nb_tetro + 1))))
		return (NULL);
	check->i = 0;
	check->mllc = nb_tetro;
	check->letter = 65;
	check->buf[nb_tetro] = NULL;
	while (check->mllc >= 0)
	{
		if (!(check->buf[check->mllc] = malloc(sizeof(char) * 21)))
			return (NULL);
		check->buf[check->mllc][20] = '\n';
		check->mllc--;
	}
	return (check);
}

char		**check_place_letter(int fd, int nb_tetro)
{
	t_check *check;

	if (!(check = check_init(nb_tetro)))
		return (NULL);
	while (check->i != nb_tetro)
	{
		check->j = 0;
		check->len = read(fd, check->buf[check->i], 20);
		check->buf[check->i][check->len] = '\0';
		if ((check->len = check_back_diez_point(check->buf[check->i])) == 0)
			return (0);
		if (nb_tetro > 1)
		{
			read(fd, &check->c, 1);
			if (check->c != '\n')
				return (0);
		}
		set_up_left(check->buf[check->i]);
		while (check->buf[check->i][check->j])
			check->j++;
		check->i++;
		check->letter++;
	}
	return (check->buf);
}
