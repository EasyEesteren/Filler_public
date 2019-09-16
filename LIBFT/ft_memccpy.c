/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 17:30:32 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/28 18:01:13 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int i, size_t n)
{
	size_t cnt;

	cnt = 0;
	while (cnt < n)
	{
		((unsigned char*)s1)[cnt] = ((unsigned char*)s2)[cnt];
		if (((unsigned char*)s2)[cnt] == ((unsigned char)i))
			return (&((unsigned char*)s1)[cnt + 1]);
		cnt++;
	}
	return (NULL);
}
