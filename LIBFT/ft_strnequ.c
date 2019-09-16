/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:00:14 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 19:25:14 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 1;
	if (n == 0)
		return (1);
	if (!str1 || !str2)
		return (0);
	while (*str1 && (*str1 == *str2) && i < n)
	{
		str1++;
		str2++;
		i++;
	}
	if (*str1 != *str2)
		return (0);
	return (1);
}
