/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:30:06 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:33:07 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

double	double_atoi(char *str)
{
	int		neg;
	double	res;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		++str;
	}
	if (*str == '.')
	{
		++str;
		res += double_atoi(str) / (pow(10, ft_strlen(str)));
	}
	return (res * neg);
}

int	correct_double(char *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == '.')
		++str;
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == '\0')
		return (1);
	return (0);
}
