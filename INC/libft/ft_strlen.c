/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:14:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:12:45 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && *str != '\0')
	{
		++str;
		++len;
	}
	return (len);
}
/*
int main(void)
{
	char *a = "sdvfb";
	int b = ft_strlen(a);	
	printf("%d", b);
}*/
