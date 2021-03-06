/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:53:44 by jadawson          #+#    #+#             */
/*   Updated: 2018/03/10 17:32:01 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int x)
{
	long	i;
	int		length;

	i = (long)x;
	length = 0;
	if (i <= 0)
	{
		length++;
		i = -i;
	}
	while (i != 0)
	{
		length++;
		i /= 10;
	}
	return (length);
}
