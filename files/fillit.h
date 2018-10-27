/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 17:55:57 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 17:55:57 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct		s_check
{
	int				i;
	int				j;
	char			letter;
	int				len;
	char			c;
	int				mllc;
	char			**buf;
	int				k;
	int				l;
	int				nb_dpl;
}					t_check;

typedef struct		s_setup
{
	int				left;
	int				up;
	int				i;
	int				lock;
	int				diez;
	int				memo;
}					t_setup;

typedef struct		s_etri
{
	char			c;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_etri	*next;
}					t_etri;

void				place_up_left(char *ttr, int b);
void				set_up_left(char *ttr);
char				**check_place_letter(int fd, int nb_tetro);
int					check_size(const int fd);
int					check_tetro(char *str, int memo, int diez);
int					check_back_diez_point(char *str);
t_etri				*ft_tetris_init(char **str, int len);
char				**ft_result(t_etri *tetris, int max);
int					ft_max(t_etri *tetris);
t_etri				*ft_up_coord(t_etri *tetris, int x, int y);
char				**ft_fill_empty(char **tab, int max);
t_etri				*ft_init_coord(t_etri *tetris);

#endif
