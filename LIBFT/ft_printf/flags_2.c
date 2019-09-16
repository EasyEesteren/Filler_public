/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 17:28:35 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/06/15 17:28:37 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_flags_con(t_attrs *stuff)
{
	if (stuff->f < -0 && stuff->f > -1 && stuff->flagzero == 0)
		stuff->width--;
	if (stuff->flaghash != 0 && stuff->precision == 0)
		stuff->width--;
}
