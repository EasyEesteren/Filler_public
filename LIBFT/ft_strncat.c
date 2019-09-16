/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:18:28 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/28 13:20:21 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(dest);
	while (0 < n && src[i] != '\0')
	{
		dest[len] = src[i];
		i++;
		len++;
		n--;
	}
	dest[len] = '\0';
	return (dest);
}
