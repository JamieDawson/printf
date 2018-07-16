/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funct_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 03:31:25 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/13 21:11:47 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		x_cap_funct(va_list ap, t_fwpl *modder)
{
	if (modder->flags & hash)
		ft_putstr("0X");
	return (ft_x_cap_base(va_arg(ap, unsigned long int)));
}

int		x_funct(va_list ap, t_fwpl *modder)
{
	(void)modder;
	return (ft_x_base(va_arg(ap, unsigned long int)));
}

int		p_funct(va_list ap, t_fwpl *modder)
{
	(void)modder;
	return (ft_p_base(va_arg(ap, unsigned long int)));
}

int		u_funct(va_list ap, t_fwpl *modder)
{
	int bc;

	bc = 0;
	if (modder->length & l)
		return (ft_u_base(va_arg(ap, unsigned long)));
	if (modder->length & ll)
		return (ft_u_base(va_arg(ap, unsigned long long)));
	if (modder->length & z)
		return (ft_u_base(va_arg(ap, size_t)));
	if (modder->length & j)
		return (ft_u_base(va_arg(ap, uintmax_t)));
	return (ft_u_base(va_arg(ap, unsigned int)));
}

int		o_funct(va_list ap, t_fwpl *modder)
{
	unsigned int o_num;

	o_num = va_arg(ap, unsigned int);
	if (modder->flags & hash && o_num > 0)
		ft_putchar('0');
	return (ft_o_base(o_num));
}
