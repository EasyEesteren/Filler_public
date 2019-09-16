/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 11:46:46 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:34:11 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *ar, char (*f)(unsigned int, char))
{
	unsigned	i;
	size_t		len;
	char		*s;

	i = 0;
	if (!ar || !f)
		return (NULL);
	len = ft_strlen(ar);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	while (i < len)
	{
		s[i] = (*f)(i, ar[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
