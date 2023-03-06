/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:40:38 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:13:56 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		new[i] = *s1;
		++i;
		++s1;
	}
	while (s2 && *s2 != '\0')
	{
		new[i] = *s2;
		++i;
		++s2;
	}
	new[i] = '\0';
	return (new);
}
