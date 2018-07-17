/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 20:19:01 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/17 15:10:30 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_apply_str(char *ret, int *bc, t_fwpl *modder)
{
	if (modder->flags & minus)
		precision_str_print(ret, bc, modder);
	return (*bc);
}

