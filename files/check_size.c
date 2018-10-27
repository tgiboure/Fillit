/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_size.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:21 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:54:21 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			check_size(int fd)
{
	int		len;
	char	*buffer;

	if (!(buffer = (char *)malloc(sizeof(char) * (545 + 1))))
		return (0);
	len = read(fd, buffer, 545);
	buffer[len] = '\0';
	if ((len + 1) % 21 != 0)
		return (0);
	free(buffer);
	return (len);
}
