/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isspace.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 22:02:57 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 22:02:57 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
			c == '\r' || c == ' ')
		return (1);
	return (0);
}
