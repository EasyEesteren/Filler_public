/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:25:10 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 11:17:33 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *ar, int n)
{
	size_t	i;

	i = ft_strlen(ar);
	while (i > 0)
	{
		if (ar[i] == ((char)n))
		{
			return (&((char*)ar)[i]);
		}
		i--;
	}
	if (ar[0] == ((char)n))
		return (&((char*)ar)[0]);
	return (NULL);
}
