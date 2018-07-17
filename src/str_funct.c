/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 20:33:33 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/17 12:18:44 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		str_print(va_list ap, t_fwpl *modder)
{
	char	*ret;
	int		bc;
	int		i;

	i = 0;
	bc = 0;
	if (modder->length)
		return(length_apply_str(ap, modder));
	ret = va_arg(ap, char *);
	if (modder->flags)
		return(flag_apply_str(ret, &bc, modder));
	if (!ret)
		ft_putstr("(null)");
	ft_putstr_bc(ret, &bc);
	return (bc);
}

int		char_funct(va_list ap, t_fwpl *modder)
{
	char	let;

	(void)modder;
	let = va_arg(ap, int);
	ft_putchar(let);
	return (1);
}

int		iord_funct(va_list ap, t_fwpl *modder)
{
	int		id;
	int		len;
	int		bc;

	id = va_arg(ap, int);
	len = ft_numlen(id);
	bc = 0;
	if ((modder->flags & plus && id >= 0) || (modder->flags & space && id >= 0))
		print_plus_or_space(modder);
	//(modder->precision > 0) ? precision_print(len, &bc, modder) : 0;
	if (modder->precision > 0)
		return(precision_print(len, &bc, modder));
	(modder->flags & zero) ? zero_print(len, modder->width, &bc, modder) : 0;
	if (modder->flags & minus)
		return(flag_apply_iord(id, len, modder, bc));
	if (modder->width)
		return(width_iord_print(id, bc, len, modder));
	ft_putnbr_bc(id, &bc);
	return (bc);
}
