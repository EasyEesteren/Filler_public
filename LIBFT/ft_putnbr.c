/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 17:43:35 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 10:41:45 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	char result;

	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	if (n < 10)
	{
		result = n + '0';
		write(1, &result, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
