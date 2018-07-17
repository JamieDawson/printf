/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_iord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 23:14:50 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/17 12:49:36 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_iord_print(int id, int bc, int len,  t_fwpl *modder)
{
	if (modder->width)
	{
		width_print(len, modder->width, &bc, modder);
		ft_putnbr_bc(id, &bc);
		return (bc);
	}
	return (0);

}
