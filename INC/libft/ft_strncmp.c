/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:55:37 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/21 09:26:12 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
	{
		return (0);
	}
	if (n == 1)
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}	
	else if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else if (*s1 == *s2)
	{
		++s1;
		++s2;
		return (ft_strncmp(s1, s2, n - 1));
	}
	else
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
}
/*int main(void)
{
	char *str1 = "hol", *str2 = "hola";
	printf("%d" "%d", ft_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}*/	
