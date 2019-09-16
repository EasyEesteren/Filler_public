/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   length.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:08:36 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:08:38 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length(const char *format, t_attrs *stuff)
{
	unsigned	i;

	i = 0;
	while (format[stuff->i] == 'h' || format[stuff->i] == 'l' \
		|| format[stuff->i] == 'L')
	{
		stuff->length[i] = format[stuff->i];
		stuff->i++;
		i++;
	}
}
