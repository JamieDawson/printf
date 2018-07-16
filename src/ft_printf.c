/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:58:35 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/12 03:54:58 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			find;
	int			count;

	count = 0;
	va_start(ap, str);
	find = parse((char*)str, ap, count);
	va_end(ap);
	return (find);
}
