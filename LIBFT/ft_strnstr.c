/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 19:31:27 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 20:10:43 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	if (!needle[0])
		return ((char*)&haystack[i]);
	else
	{
		while (haystack[i] && (i < len))
		{
			while ((haystack[i + n] == needle[n]) && needle[n] \
				&& ((i + n) < len))
				n++;
			if (!needle[n])
				return ((char *)&haystack[i]);
			n = 0;
			i++;
		}
	}
	return (NULL);
}
