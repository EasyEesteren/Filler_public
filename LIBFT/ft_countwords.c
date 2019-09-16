/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_countwords.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 10:27:07 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 11:57:43 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countwords(const char *ar, char c)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 0;
	while (ar[i])
	{
		if (ar[i] != c)
			cnt++;
		while (ar[i] != c && ar[i + 1])
			i++;
		i++;
	}
	return (cnt);
}
