/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:54:16 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/15 23:31:51 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define COUNT_TYPES	12

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

enum	e_flags{
	plus = 1,
	minus = 1 << 1,
	zero = 1 << 2,
	hash = 1 << 3,
	space = 1 << 4
};

enum	e_length{
	hh = 1,
	h = 1 << 1,
	l = 1 << 2,
	ll = 1 << 3,
	j = 1 << 4,
	z = 1 << 5
};

typedef struct	s_fwpl
{
	int			flags;
	int			width;
	int			precision;
	int			length;
}				t_fwpl;

int				ft_printf(const char *str, ...);
int				parse(char *str, va_list ap, int count);
int				type_check(char *type, va_list ap);
int				str_print(va_list ap, t_fwpl *modder);
int				char_funct(va_list ap, t_fwpl *modder);
int				iord_funct(va_list ap, t_fwpl *modder);
int				ft_x_base(size_t num);
int				x_funct(va_list ap, t_fwpl *modder);
int				p_funct(va_list ap, t_fwpl *modder);
int				ft_p_base(unsigned long int number);
int				u_funct(va_list ap, t_fwpl *modder);
int				ft_u_base(size_t num);
int				ft_o_base (unsigned long int num);
int				o_funct(va_list ap, t_fwpl *modder);
int				c_wide_funct(va_list ap, t_fwpl *modder);
int				c_wide_handle(wchar_t c);
int				s_wide_funct(va_list ap, t_fwpl *modder);
void			ft_w_putstr(wchar_t *str);
int				s_wide_strlen(wchar_t *str);
int				d_wide_funct(va_list ap, t_fwpl *modder);
int				ft_x_cap_base(size_t number);
int				x_cap_funct(va_list ap, t_fwpl *modder);
void			ft_putnbr_bc(size_t nb, int *bc);
void			zero_print(int iord_len, int zero,
						int *bc, t_fwpl *modder);
void			width_print(int iord_len, int width_size,
						int *bc, t_fwpl *modder);
void			precision_print(int iord_len,
						int *bc, t_fwpl *modder);
void			precision_str_print(char *str,
						int *bc, t_fwpl *modder);
int				ptr_is_flag(char c);
int				ptr_is_length(char c);
int				ptr_str_is_num(char c);
void			print_plus_or_space(t_fwpl *modder);
void			ft_putstr_bc(char const *s, int *bc);

#endif
