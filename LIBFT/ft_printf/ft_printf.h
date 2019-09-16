/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 19:08:25 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/05/28 19:08:27 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <unistd.h>

# define FERROR	-1

typedef struct		s_attr
{
	int				i;
	int				flagminus;
	int				flagplus;
	int				flaghash;
	int				flagzero;
	int				flagspace;
	int				width;
	int				precision;
	int				cnt;
	int				len;
	int				save;
	int				res;
	int				oct_len;
	char			*length;
	char			*str;
	char			width_c;
	long long int	x;
	long double		f;
	unsigned \
	long long		u_x;
}					t_attrs;

int					ft_printf(const char *format, ...);
void				flags(t_attrs *stuff, const char *format);
void				width(va_list args, const char *format, t_attrs *stuff);
void				precision(va_list args, const char *format, t_attrs *stuff);
void				length(const char *format, t_attrs *stuff);
void				specifier(va_list args, const char *format, t_attrs *stuff);
void				hexadecimal(unsigned long long int dec, t_attrs *stuff);
void				hexadecimal_upper(unsigned long long int dec, \
					t_attrs *stuff);
void				put_flag(t_attrs *stuff, long long x);
void				width_dgt(t_attrs *stuff, const char *format);
void				width_dgt_aft(t_attrs *stuff, const char *format);
void				width_sc(const char *format, t_attrs *stuff);
int					put_sc(va_list args, const char *format, t_attrs *stuff);
void				width_dgt_ux(t_attrs *stuff, int len);
void				precision_dgt(t_attrs *stuff);
void				precision_dgt_ux(t_attrs *stuff, int len);
void				handle_float(t_attrs *stuff, va_list args);
void				handle_lfloat(t_attrs *stuff, va_list args);
int					specifier_f(t_attrs *stuff, va_list args, \
					const char *format);
void				handle_flags(t_attrs *stuff, const char *format);
void				handle_lflags (t_attrs *stuff);
void				width_f(t_attrs *stuff);
void				octal(unsigned long long int dec, t_attrs *stuff);
void				octal_len(unsigned long long int dec, t_attrs *stuff);
int					pointer_conv(va_list args, t_attrs *stuff);
int					round_nines(char *ar, t_attrs *stuff);
void				no_specifier(t_attrs *stuff, const char *format);
void				conversion_handler(t_attrs *stuff, const char *format, \
					va_list args);
void				place_hexa(t_attrs *stuff, char hexa[]);
void				precision_oct(t_attrs *stuff);
void				width_dgt_place(t_attrs *stuff);
void				create_hexa_low(unsigned long long int dec, t_attrs *stuff);
void				create_hexa_up(unsigned long long int dec, t_attrs *stuff);
void				precision_oct_nxt(t_attrs *stuff);
void				precision_dgt_nxt(t_attrs *stuff);
void				place_oct_u(const char *format, t_attrs *stuff);
void				put_dgt(t_attrs *stuff, const char *format);
double				find_dec(long double a);
void				zero_precision_f(t_attrs *stuff);
void				l_flags_con(t_attrs *stuff);
void				put_num(t_attrs *stuff, char *ar);
void				put_numl(t_attrs *stuff, char *ar);
void				put_plus(t_attrs *stuff);

#endif
