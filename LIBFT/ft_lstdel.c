/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 10:38:04 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/31 16:57:28 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*save;
	t_list	*anxt;

	save = *alst;
	while (save)
	{
		anxt = save->next;
		del((save->content), (save->content_size));
		free(save);
		save = anxt;
	}
	*alst = NULL;
}
