/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:54:10 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 21:44:42 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_init(char **str, int len)
{
	t_etri	*tetris;

	tetris = ft_tetris_init(str, ((len - 1) / 20));
	tetris = ft_init_coord(tetris);
	str = ft_result(tetris, ft_max(tetris));
	return (str);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		len;
	char	**str;

	i = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		len = check_size(fd);
		if (len <= 0 || fd == -1)
			return (ft_print_error());
		close(fd);
		fd = open(argv[1], O_RDONLY);
		if ((str = check_place_letter(fd, (len + 1) / 21)) == NULL)
			return (ft_print_error());
		close(fd);
		str = ft_init(str, len);
		while (str[i])
			ft_putendl(str[i++]);
	}
	return (0);
}
