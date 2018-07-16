/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funct_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:50:37 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/13 21:12:05 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		c_wide_funct(va_list ap, t_fwpl *modder)
{
	wchar_t let;

	(void)modder;
	let = va_arg(ap, wchar_t);
	return (c_wide_handle(let));
}

int		s_wide_funct(va_list ap, t_fwpl *modder)
{
	wchar_t *ret;

	(void)modder;
	ret = va_arg(ap, wchar_t *);
	ft_w_putstr(ret);
	return (s_wide_strlen((wchar_t *)ret));
}

int		d_wide_funct(va_list ap, t_fwpl *modder)
{
	int				bc;
	long			dw;

	bc = 0;
	(void)modder;
	dw = va_arg(ap, long);
	ft_putnbr_bc(dw, &bc);
	return (bc);
}
