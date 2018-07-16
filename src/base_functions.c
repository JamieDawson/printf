/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 23:00:35 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/12 20:20:51 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_x_base(size_t number)
{
	char				print[24];
	unsigned int		i;

	i = 0;
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	while (number)
	{
		print[i++] = "0123456789abcdef"[number % 16];
		number /= 16;
	}
	print[i] = '\0';
	ft_strrev(print);
	ft_putstr(print);
	return (i);
}

int		ft_x_cap_base(size_t number)
{
	char				print[24];
	unsigned int		i;

	i = 0;
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	while (number)
	{
		print[i++] = "0123456789ABCDEF"[number % 16];
		number /= 16;
	}
	print[i] = '\0';
	ft_strrev(print);
	ft_putstr(print);
	return (i);
}

int		ft_p_base(unsigned long int number)
{
	char				print[24];
	unsigned int		i;

	i = 0;
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	ft_putstr("0x");
	while (number)
	{
		print[i++] = "0123456789abcdef"[number % 16];
		number /= 16;
	}
	print[i] = '\0';
	ft_strrev(print);
	ft_putstr(print);
	i += 2;
	return (i);
}

int		ft_u_base(size_t number)
{
	char				print[24];
	unsigned int		i;

	i = 0;
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	while (number)
	{
		print[i] = (number % 10) + 48;
		number /= 10;
		i++;
	}
	print[i] = '\0';
	ft_strrev(print);
	ft_putstr(print);
	return (i);
}

int		ft_o_base(unsigned long int number)
{
	char				print[24];
	unsigned int		i;

	i = 0;
	if (number == 0)
	{
		print[i] = '0';
		i++;
	}
	while (number)
	{
		print[i] = (number % 8) + 48;
		number /= 8;
		i++;
	}
	print[i] = '\0';
	ft_strrev(print);
	ft_putstr(print);
	return (i);
}
