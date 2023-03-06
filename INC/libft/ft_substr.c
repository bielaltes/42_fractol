/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:21:53 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/22 19:12:58 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	count_max(char const *s, unsigned int start, size_t len)
{
	size_t	n;

	n = 0;
	while (start > 0 && *s != '\0')
	{
		++s;
		--start;
	}
	while (len > 0 && *s != '\0')
	{
		++n;
		--len;
		++s;
	}
	return (n);
}	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	truelen;
	size_t	i;

	i = 0;
	truelen = count_max(s, start, len);
	new = malloc(sizeof(char) * (truelen + 1));
	if (!new)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*new = '\0';
		return (new);
	}
	while (i < truelen)
	{
		new[i] = s[start + i];
		++i;
	}
	new[truelen] = '\0';
	return (new);
}
