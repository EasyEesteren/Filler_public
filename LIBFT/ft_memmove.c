/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 11:15:45 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/31 17:03:47 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*nsrc;
	unsigned char	*ndest;

	nsrc = (unsigned char*)src;
	ndest = (unsigned char*)dest;
	i = 0;
	if (ndest < nsrc)
	{
		while (i < n)
		{
			ndest[i] = nsrc[i];
			i++;
		}
	}
	if (ndest > nsrc)
	{
		while (n > 0)
		{
			n--;
			ndest[n] = nsrc[n];
		}
	}
	return (dest);
}
