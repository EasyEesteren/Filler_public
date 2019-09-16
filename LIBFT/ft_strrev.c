/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/17 18:20:27 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/17 18:20:29 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*temp;
	size_t	i;
	int		y;

	i = 0;
	y = ft_strlen(str);
	temp = (char*)malloc(sizeof(char) * y + 1);
	if (temp == NULL)
		return (NULL);
	temp[y] = '\0';
	y--;
	while (i < ft_strlen(str))
	{
		temp[y] = str[i];
		y--;
		i++;
	}
	free(str);
	return (temp);
}
