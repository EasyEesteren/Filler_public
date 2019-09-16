/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 16:09:36 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/01/12 18:34:46 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *cpy)
{
	size_t	i;

	i = 0;
	while (cpy[i] != '\0')
	{
		dest[i] = cpy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
