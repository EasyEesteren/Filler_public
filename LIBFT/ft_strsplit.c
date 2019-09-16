/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 18:03:12 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/03/04 16:43:32 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	if (!s)
		return (NULL);
	return (ft_splithelp(s, c, y, x));
}
