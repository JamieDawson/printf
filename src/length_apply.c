/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:21:06 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/17 14:03:11 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_apply_str(va_list ap, t_fwpl *modder)
{
	if ((modder->length & l) == l)
		return (s_wide_funct(ap, modder));
	return (0);
}

/*
int	width_print_str(int str_len, int width_size, int *bc, t_fwpl *modder)
{
	while (str_len < width_size)
	{
		ft_putchar(' ');
		str_len++;
		*bc += 1;
		modder->width -= 1;
	}
	return (*bc);
}

