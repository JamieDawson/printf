/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_apply_num_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 22:11:15 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/16 23:03:37 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_apply_iord(int id, int len, t_fwpl *modder, int bc)
{
	if (modder->flags & minus)
	{
		ft_putnbr_bc(id, &bc);
		(width_print(len, modder->width, &bc, modder));
	}
	return (bc);
}
