/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_u_long.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 12:49:41 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/02 12:49:51 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_u_long(unsigned long long int n)
{
	char result;

	if (n < 10)
	{
		write(1, "a", 1);
		result = n + '0';
		write(1, &result, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
