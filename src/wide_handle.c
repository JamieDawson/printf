/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 00:57:42 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/12 03:24:49 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		c_wide_handle(wchar_t c)
{
	write(1, &c, 1);
	return (1);
}

int		s_wide_strlen(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_w_putstr(wchar_t *s)
{
	int x;

	x = -1;
	while (s[++x] != '\0')
	{
		write(1, &s[x], 1);
	}
}

void	print_plus_or_space(t_fwpl *modder)
{
	if (modder->flags & plus)
	{
		ft_putchar('+');
		modder->width -= 1;
	}
	if (modder->flags & space)
	{
		ft_putchar(' ');
		modder->width -= 1;
	}
}

void	ft_putstr_bc(char const *s, int *bc)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
		*bc += 1;
	}
}
