/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strsub.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/16 17:43:28 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/07/16 17:43:31 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*strsub;
	int		state;

	i = 0;
	strsub = (char *)malloc(len + 1);
	state = 0;
	if (s != NULL)
	{
		if (strsub != NULL)
		{
			while (i < len)
			{
				strsub[i] = s[start];
				if (strsub[i] == '\0')
					state = 1;
				i++;
				start++;
			}
			if (state != 1)
				strsub[i] = '\0';
		}
	}
	return (strsub);
}
