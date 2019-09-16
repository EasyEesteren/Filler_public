/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splithelp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 14:46:08 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/03/04 17:32:11 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_allocate(char const *s, char c)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * (ft_char_ignore(s, c) + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}

char			**ft_splithelp(char const *s, char c, size_t y, size_t x)
{
	char	**ar;
	int		cnt;

	ar = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1));
	if (ar == NULL)
		return (NULL);
	cnt = 0;
	while (x < ft_countwords(s, c))
	{
		ar[x] = ft_allocate(s, c);
		while (s[cnt] == c)
			cnt++;
		while (s[cnt] != c && s[cnt])
		{
			ar[x][y] = s[cnt];
			y++;
			cnt++;
		}
		ar[x][y] = '\0';
		y = 0;
		x++;
	}
	ar[x] = NULL;
	return (ar);
}
