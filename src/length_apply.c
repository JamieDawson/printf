/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:21:06 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/16 22:08:29 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_apply_str(va_list ap, t_fwpl *modder)
{
	if ((modder->length & l) == l)
		return (s_wide_funct(ap, modder));
	return (0);
}
