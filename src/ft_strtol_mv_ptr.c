/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_mv_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:37:19 by rcammaro          #+#    #+#             */
/*   Updated: 2021/04/15 15:37:35 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	safe_add(long nbr, char c, int sign)
{
	if (nbr > LONG_MIN / 10 && nbr < LONG_MAX / 10)
		return (nbr * 10 + sign * (c - '0'));
	if (sign == 1 && nbr > LONG_MAX / 10)
		return (LONG_MAX);
	if (sign == 1 && nbr == LONG_MAX / 10 && (c - '0') > LONG_MAX % 10)
		return (LONG_MAX);
	if (sign == -1 && nbr < LONG_MIN / 10)
		return (LONG_MIN);
	if (sign == -1 && nbr == LONG_MIN / 10 && -(c - '0') < LONG_MIN % 10)
		return (LONG_MIN);
	return (nbr * 10 + sign * (c - '0'));
}

long	ft_strtol_mv_ptr(char **nptr)
{
	int			sign;
	long int	nbr;

	while (ft_isspace(**nptr))
		(*nptr)++;
	sign = 1;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	nbr = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		nbr = safe_add(nbr, **nptr, sign);
		(*nptr)++;
	}
	return (nbr);
}
