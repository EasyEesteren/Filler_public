/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:30:34 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:33:59 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	sz2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sz2 = ft_strlen(s2);
	result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + sz2 + 1));
	if (result == NULL)
		return (NULL);
	sz2 = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[sz2])
	{
		result[i] = s2[sz2];
		i++;
		sz2++;
	}
	result[i] = '\0';
	return (result);
}
