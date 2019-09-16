/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 17:36:32 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 18:55:54 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *ar, int fd)
{
	int		i;

	i = 0;
	if (ar)
	{
		while (ar[i])
		{
			write(fd, &ar[i], 1);
			i++;
		}
	}
}
