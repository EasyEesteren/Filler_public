/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:31:23 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/29 17:46:31 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	unsigned	n;
	unsigned	len;

	n = 0;
	len = ft_strlen(dest);
	while (src[n])
	{
		dest[len + n] = src[n];
		n++;
	}
	dest[len + n] = '\0';
	return (dest);
}
