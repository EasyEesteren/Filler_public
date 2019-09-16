/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 13:07:14 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 15:44:19 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*hsave;

	hsave = lst;
	if (lst != NULL || f != NULL)
	{
		while (hsave)
		{
			(*f)(hsave);
			hsave = hsave->next;
		}
	}
}
