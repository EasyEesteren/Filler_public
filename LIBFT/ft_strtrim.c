/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 16:11:31 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:12:07 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_onlywhitespace(char const *s)
{
	while (*s)
	{
		if (!ft_iswhitespace(*s))
			return (0);
		s++;
	}
	return (1);
}

static	char	*ft_ret(void)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

static	char	*ft_trim(size_t len, size_t i, size_t len2, char const *s)
{
	int		q;
	char	*res;

	q = 0;
	res = (char*)malloc(sizeof(char) * (len - i) + 2);
	if (res == NULL)
		return (NULL);
	len2 = len - i + 1;
	while (len2 > 0)
	{
		res[q] = s[i];
		len2--;
		i++;
		q++;
	}
	res[q] = '\0';
	return (res);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*res;
	size_t	len2;

	if (!s)
		return (NULL);
	if (ft_onlywhitespace(s))
		return (ft_ret());
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	len = ft_strlen(s) - 1;
	while (s[len] == '\t' || s[len] == ' ' || s[len] == '\n')
		len--;
	len2 = len - i + 1;
	res = ft_trim(len, i, len2, s);
	return (res);
}
