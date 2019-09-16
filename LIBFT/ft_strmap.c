/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 14:50:00 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:34:23 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*ar;
	unsigned	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	ar = (char*)malloc(sizeof(char) * i + 1);
	if (ar == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ar[i] = f(s[i]);
		i++;
	}
	ar[i] = '\0';
	return (ar);
}
