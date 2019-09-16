/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 12:37:21 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:34:52 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ar;

	i = 0;
	ar = (char*)malloc(sizeof(char) * size + 1);
	if (ar == NULL)
		return (NULL);
	while (i <= size)
	{
		ar[i] = '\0';
		i++;
	}
	return (ar);
}
