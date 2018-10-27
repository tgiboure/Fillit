/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countdigits.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 22:02:56 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 22:02:56 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countdigits(int n)
{
	int i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
