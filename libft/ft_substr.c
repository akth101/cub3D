/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:07:55 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/20 13:07:56 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	make_size(size_t max_i, unsigned int start, size_t len)
{
	if (max_i - start < len)
		return (max_i - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_i;
	size_t	i;
	size_t	size;
	char	*p;

	max_i = ft_strlen(s);
	if (max_i == 0 || max_i < start)
		return (ft_strdup(""));
	size = make_size(max_i, start, len);
	p = (char *)malloc(size + 1);
	if (p == (void *)0)
		return (0);
	i = 0;
	while (len && s[start])
	{
		p[i++] = s[start++];
		len--;
	}
	p[i] = '\0';
	return (p);
}
