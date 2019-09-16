/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:23:26 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 10:44:45 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)n)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return (&((char*)s)[i]);
}
