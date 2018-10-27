/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 22:02:58 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 22:02:58 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (!(ptr = malloc(sizeof(unsigned char) * (size))))
		return (NULL);
	while (i <= size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
