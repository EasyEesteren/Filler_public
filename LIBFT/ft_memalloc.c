/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:48:59 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 11:52:56 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ar;

	ar = NULL;
	if (size)
	{
		ar = malloc(sizeof(0) * size);
		if (ar == NULL)
			return (NULL);
		while (size)
			ar[--size] = 0;
	}
	return ((void *)ar);
}
