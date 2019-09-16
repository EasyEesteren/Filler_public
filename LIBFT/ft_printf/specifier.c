/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:12:04 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:12:05 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	place_dgt(va_list args, const char *format, t_attrs *stuff)
{
	if (format[stuff->i] == 'i' || format[stuff->i] == 'd')
		stuff->x = va_arg(args, int);
	else if (format[stuff->i] != 'x' && format[stuff->i] != 'X')
		stuff->x = va_arg(args, long long int);
	handle_flags(stuff, format);
	if (stuff->flagminus == 0 && stuff->precision < stuff->width \
		&& format[stuff->i] != 'x' && format[stuff->i] != 'X')
		width_dgt(stuff, format);
	if ((stuff->precision > stuff->width || stuff->flagminus != 0) && \
		format[stuff->i] != 'x' && format[stuff->i] != 'X' \
		&& format[stuff->i] != 'o' && format[stuff->i] != 'u')
		precision_dgt(stuff);
	if (format[stuff->i] != 'x' && format[stuff->i] != 'X' \
		&& format[stuff->i] != 'o' && format[stuff->i] != 'u')
		stuff->res += ft_nbrlen(stuff->x);
	if (format[stuff->i] == 'i' || format[stuff->i] == 'd')
	{
		if (stuff->precision != 0 || stuff->x != 0)
			ft_putnbr(stuff->x);
		else
			stuff->res--;
	}
	else if (format[stuff->i] == 'u' || format[stuff->i] == 'o')
		place_oct_u(format, stuff);
	conversion_handler(stuff, format, args);
}

static	void	handle_octal(t_attrs *stuff)
{
	if (stuff->flagminus == 0)
		width_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
	precision_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
	if (stuff->flaghash == 1 && stuff->precision <= 0)
		ft_putchar('0');
	if (ft_strcmp(stuff->length, "ll") == 0 || \
	ft_strcmp(stuff->length, "l") == 0)
		octal(stuff->u_x, stuff);
	else if (ft_strcmp(stuff->length, "h") == 0)
		octal((unsigned short)stuff->u_x, stuff);
	else if (ft_strcmp(stuff->length, "hh") == 0)
		octal((unsigned char)stuff->u_x, stuff);
	if (stuff->flagminus != 0)
		width_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
}

static	int		specifier_oux(va_list args, const char *format, t_attrs *stuff)
{
	stuff->u_x = va_arg(args, unsigned long long);
	handle_flags(stuff, format);
	if (format[stuff->i] == 'o')
		handle_octal(stuff);
	else if ((ft_strcmp(stuff->length, "l") == 0 \
	|| ft_strcmp(stuff->length, "ll") == 0 \
	|| ft_strcmp(stuff->length, "h") == 0 \
	|| ft_strcmp(stuff->length, "hh") == 0) && format[stuff->i] == 'u')
	{
		if (stuff->flagminus == 0)
			width_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
		precision_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
		stuff->res += ft_nbrlen(stuff->u_x);
		ft_put_u_long(stuff->u_x);
		if (stuff->flagminus != 0)
			width_dgt_ux(stuff, ft_nbrlen(stuff->u_x));
	}
	else if (format[stuff->i] == 'x' || format[stuff->i] == 'X')
		conversion_handler(stuff, format, args);
	else
		return (0);
	return (1);
}

static	int		specifier_dif(va_list args, const char *format, t_attrs *stuff)
{
	if (ft_strcmp(stuff->length, "h") == 0 && (format[stuff->i] == 'i' || \
		format[stuff->i] == 'd'))
		stuff->x = (short int)va_arg(args, int);
	else if (ft_strcmp(stuff->length, "hh") == 0 && (format[stuff->i] == 'i' \
	|| format[stuff->i] == 'd'))
		stuff->x = (signed char)va_arg(args, int);
	else if (ft_strcmp(stuff->length, "l") == 0 && (format[stuff->i] == 'i' \
	|| format[stuff->i] == 'd'))
		stuff->x = va_arg(args, long int);
	else if (ft_strcmp(stuff->length, "ll") == 0 && (format[stuff->i] == 'i' \
	|| format[stuff->i] == 'd'))
		stuff->x = va_arg(args, long long int);
	else if (specifier_f(stuff, args, format) == 1)
		return (1);
	else
		return (0);
	handle_flags(stuff, format);
	if (stuff->precision < stuff->width && stuff->flagminus == 0)
		width_dgt(stuff, format);
	else
		precision_dgt(stuff);
	put_dgt(stuff, format);
	return (1);
}

void			specifier(va_list args, const char *format, t_attrs *stuff)
{
	if (ft_strlen(stuff->length) > 0)
	{
		if (!(specifier_dif(args, format, stuff)))
			specifier_oux(args, format, stuff);
	}
	else if (format[stuff->i] == 'i' || format[stuff->i] == 'd' \
	|| format[stuff->i] == 'u' || format[stuff->i] == 'o'\
	|| format[stuff->i] == 'x' || format[stuff->i] == 'X')
		place_dgt(args, format, stuff);
	else if (format[stuff->i] == 's' || format[stuff->i] == 'c')
		put_sc(args, format, stuff);
	else if (format[stuff->i] == 'f')
		handle_float(stuff, args);
	else if (format[stuff->i] == 'p')
		pointer_conv(args, stuff);
	else
		no_specifier(stuff, format);
	free(stuff->length);
}
