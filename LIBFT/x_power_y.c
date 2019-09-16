/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_power_y.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/04 15:01:52 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/04 15:01:55 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	xy_power(int x, int y)
{
	unsigned long long int power;

	power = 1;
	while (y > 0)
	{
		power = power * x;
		y--;
	}
	return (power);
}
