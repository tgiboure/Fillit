/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_up_left.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:05 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:54:05 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void		place_up_left(char *ttr, int b)
{
	int		i;
	int		diez;

	i = 0;
	diez = 4;
	while (diez != 0)
	{
		if (ttr[i] == '#')
		{
			ttr[i - b] = '#';
			ttr[i] = '.';
			diez--;
		}
		i++;
	}
}

void		set_up_while(char *ttr, t_setup *set)
{
	while (ttr[set->i] != '\n')
	{
		if (ttr[set->i] == '#')
		{
			set->diez--;
			if (set->lock != 1)
				set->lock = 1;
		}
		if (set->lock == 0)
			set->memo++;
		if (set->lock == 1 && set->left > set->memo)
			set->left = set->memo;
		set->i++;
	}
}

void		set_up_left(char *ttr)
{
	t_setup	*set;

	if (!(set = malloc(sizeof(t_setup))))
		return ;
	set->i = 0;
	set->up = 0;
	set->left = 4;
	set->diez = 4;
	while (set->diez != 0)
	{
		set->lock = 0;
		set->memo = 0;
		set_up_while(ttr, set);
		if (set->lock == 0)
			set->up++;
		set->i++;
	}
	if (set->up * 5 + set->left != 0)
		place_up_left(ttr, (set->up * 5) + set->left);
}
