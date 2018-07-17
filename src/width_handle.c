/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 21:17:19 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/17 14:31:50 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_bc(size_t nb, int *bc)
{
	long long nnb;

	nnb = nb;
	if (nnb < 0)
	{
		ft_putchar('-');
		nnb = -nnb;
		*bc += 1;
	}
	if (nnb >= 10)
	{
		ft_putnbr_bc(nnb / 10, bc);
		ft_putnbr_bc(nnb % 10, bc);
	}
	else
	{
		ft_putchar(nnb + '0');
		*bc += 1;
	}
}

void	width_print(int iord_len, int width_size, int *bc, t_fwpl *modder)
{
	while (iord_len < width_size)
	{
		ft_putchar(' ');
		iord_len++;
		*bc += 1;
		modder->width -= 1;
	}
}

void	zero_print(int iord_len, int zero, int *bc, t_fwpl *modder)
{
	int z;

	z = zero;
	while (iord_len < zero)
	{
		ft_putchar('0');
		iord_len++;
		*bc += 1;
		modder->width -= 1;
	}
}

void	precision_print(int iord_len, int *bc, t_fwpl *modder)
{
	int get_pre;
	int get_empty;

	(void)bc;
	get_pre = modder->precision - iord_len;
	get_empty = modder->width - modder->precision;
	while (modder->precision > modder->width && get_pre > 0)
	{
		ft_putchar('0');
		get_pre--;
		modder->width -= 1;
	}
	while (modder->width > modder->precision && get_empty > 0)
	{
		ft_putchar(' ');
		get_empty--;
		modder->width -= 1;
		if (get_empty == 0 && get_pre > 0)
		{
			ft_putchar('0');
			get_pre--;
			modder->width -= 1;
		}
	}
}

void	precision_str_print(char *str, int *bc, t_fwpl *modder)
{
	int i;
	int rest_w;
	int w;
	int p;

	w = modder->width;
	p = modder->precision;
	rest_w = w - p;
	i = 0;
	while (w > p & modder->precision > 0)
	{
		ft_putchar(str[i]);
		i++;
		modder->precision -= 1;
		bc += 1;
	}
	while (rest_w > 0)
	{
		ft_putchar(' ');
		rest_w--;
		bc += 1;
	}
}
