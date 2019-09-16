/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:34:37 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/02/03 10:43:22 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char result;

	if (n == -2147483648)
	{
		ft_putstr_fd("-214748364", fd);
		n = 8;
	}
	else if (n < 0 && n > -2147483648)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	if (n < 10 && n > -2147483648)
	{
		result = n + '0';
		write(fd, &result, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
