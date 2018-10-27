/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jfeve <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 22:02:58 by jfeve        #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 22:02:58 by jfeve       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *tmp;

	current = *alst;
	while (current != NULL)
	{
		tmp = current->next;
		del(current->content, current->content_size);
		free(current);
		current = tmp;
	}
	*alst = NULL;
}
