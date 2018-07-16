/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 19:00:04 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/13 21:11:52 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../inc/global.h"

char	*get_flag(char *type, t_fwpl *stuff)
{
	stuff->flags = 0;
	if (ptr_is_flag(*type))
	{
		while (ptr_is_flag(*type))
		{
			if (*type == '+')
				stuff->flags |= plus;
			if (*type == '-')
				stuff->flags |= minus;
			if (*type == '0')
				stuff->flags |= zero;
			if (*type == '#')
				stuff->flags |= hash;
			if (*type == ' ')
				stuff->flags |= space;
			type++;
			if (!(ptr_is_flag(*type)))
				return (type);
		}
	}
	return (type);
}

char	*get_length(char *type, t_fwpl *stuff)
{
	stuff->length = 0;
	if (ptr_is_length(*type))
	{
		if (*type == 'h' && (*type + 1 != 'h'))
			stuff->length |= h;
		if (*(type + 1) == 'h')
		{
			stuff->length |= hh;
			return (type + 2);
		}
		if (*type == 'l' && (*type + 1 != 'l'))
			stuff->length |= l;
		if (*(type + 1) == 'l')
		{
			stuff->length |= ll;
			return (type + 2);
		}
		if (*type == 'j')
			stuff->length |= j;
		if (*type == 'z')
			stuff->length |= z;
		return (type + 1);
	}
	return (type);
}

char	*get_width(char *type, t_fwpl *stuff)
{
	int size;

	size = 0;
	stuff->width = -1;
	if (ptr_str_is_num(*type))
	{
		size = ft_atoi(type);
		stuff->width = size;
		return (type + ft_numlen(size));
	}
	return (type);
}

char	*get_precision(char *type, t_fwpl *stuff)
{
	int	size;

	size = 0;
	stuff->precision = -1;
	if (*type == '.')
	{
		type++;
		if (ptr_str_is_num(*type))
		{
			size = ft_atoi(type);
			stuff->precision = size;
			return (type + ft_numlen(size));
		}
	}
	return (type);
}

int		type_check(char *type, va_list ap)
{
	int		i;
	int		send;
	t_fwpl	stuff;

	i = -1;
	type = get_flag(type, &stuff);
	type = get_width(type, &stuff);
	type = get_precision(type, &stuff);
	type = get_length(type, &stuff);
	while (++i < COUNT_TYPES)
	{
		if (dispatch[i].type_find == *type)
			send = dispatch[i].c(ap, &stuff);
	}
	return (send);
}
