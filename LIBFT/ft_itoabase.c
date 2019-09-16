/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoabase.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/17 18:16:05 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/17 18:16:14 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_power(int n, int po)
{
	if (po == 0)
		return (1);
	return (n * ft_power(n, po - 1));
}

static	void		initialize(long long *sign, int *length)
{
	*sign = 1;
	*length = 1;
}

char				*ft_itoabase(long long value, int base)
{
	long long	nb;
	int			length;
	char		*result;
	long long	sign;
	long long	i;

	nb = value;
	initialize(&sign, &length);
	while (ft_power(base, length) <= nb)
		length++;
	result = (char *)malloc(sizeof(char) * (length + 2));
	i = 0;
	while (i < length)
	{
		if (base <= 10 || (base > 10 && (nb % base) < 10))
			result[i] = (nb % base) + 48;
		else
			result[i] = (nb % base) - 10 + 97;
		nb /= base;
		i++;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_strrev(result));
}
