/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 18:21:06 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/16 18:31:58 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		length_apply(va_list ap, t_fwpl *modder)
{
	if ((modder->length & l) == l)
		return (s_wide_funct(ap, modder));
}
