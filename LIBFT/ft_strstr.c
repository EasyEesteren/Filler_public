/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:45:51 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 13:00:09 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hay;
	size_t	save;

	hay = 0;
	save = 0;
	if (!needle[0])
		return ((char*)&haystack[hay]);
	else
	{
		while (haystack[hay])
		{
			while ((haystack[hay + save] == needle[save]) && needle[save])
				save++;
			if (needle[save] == '\0')
				return ((char*)&haystack[hay]);
			save++;
			save = 0;
			hay++;
		}
	}
	return (NULL);
}
