/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 12:00:35 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/04 19:32:59 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ar;
	size_t	i;
	size_t	len;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	ar = (char*)malloc(sizeof(char) * len + 1);
	if (ar == NULL)
		return (NULL);
	ar[len] = '\0';
	if (n < 0)
	{
		ar[i] = '-';
		i++;
		n = n * -1;
	}
	while (i < len)
	{
		len--;
		ar[len] = (n % 10) + '0';
		n /= 10;
	}
	return (ar);
}
