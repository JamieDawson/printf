/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 21:46:34 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/12 02:14:11 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		is_type(char c)
{
	return (c == 's' || c == 'c' || c == 'i' || c == 'd' || c == 'x'
			|| c == 'u' || c == 'o' || c == 'p' || c == 'C' || c == 'S'
			|| c == 'D' || c == 'X') ? (1) : (0);
}

int				parse(char *str, va_list ap, int count)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			count++;
			i++;
		}
		else	if (str[i] == '%')
		{
			count += type_check(&str[i + 1], ap);
			while (!(is_type(str[++i])))
				;
		}
		else
		{
			ft_putchar(str[i]);
			count++;
		}
		i++;
	}
	return (count);
}
