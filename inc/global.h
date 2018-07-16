/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadawson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:54:39 by jadawson          #+#    #+#             */
/*   Updated: 2018/07/15 23:55:52 by jadawson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "../ft_printf.h"

# define SOMETHING typedef int (*single_s_type) (va_list, t_fwpl *)

SOMETHING;

typedef struct	s_type
{
	char			type_find;
	single_s_type	c;
}				t_type;

t_type	g_dispatch[] = {
	{'s', str_print},
	{'c', char_funct},
	{'i', iord_funct},
	{'d', iord_funct},
	{'x', x_funct},
	{'u', u_funct},
	{'o', o_funct},
	{'p', p_funct},
	{'C', c_wide_funct},
	{'S', s_wide_funct},
	{'D', d_wide_funct},
	{'X', x_cap_funct}
};

#endif
