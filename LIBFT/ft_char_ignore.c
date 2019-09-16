/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_ignore.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 09:40:41 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 14:32:55 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_char_ignore(const char *ar, char c)
{
	size_t	i;
	size_t	result;

	if (ar)
	{
		result = 0;
		i = 0;
		while (ar[i])
		{
			if (ar[i] != c)
				result++;
			i++;
		}
		return (result);
	}
	return (0);
}
