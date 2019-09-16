/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 11:19:50 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 11:00:14 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	len = ft_strlen(src) + len_dest;
	i = 0;
	if (n <= len_dest)
		return (ft_strlen(src) + n);
	i = 0;
	while ((i < n - (len - ft_strlen(src)) - 1) && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len);
}
