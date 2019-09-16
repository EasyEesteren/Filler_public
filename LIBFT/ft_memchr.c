/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 12:29:33 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/16 14:52:46 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (((unsigned const char *)str)[cnt] == (unsigned char)c)
			return ((void *)&((unsigned const char *)str)[cnt]);
		cnt++;
	}
	return (NULL);
}
