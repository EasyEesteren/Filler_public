/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_nline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/06 16:22:44 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/06 16:22:46 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	ft_count_nline(const char *s)
{
	unsigned	i;
	unsigned	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			cnt++;
		i++;
	}
	return (cnt);
}
