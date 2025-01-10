/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:04:36 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 15:04:37 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_str(const char *stack, const char *find, size_t len, size_t i)
{
	while (i < len && stack[i] == *find && *find)
	{
		find++;
		i++;
	}
	if (!(*find))
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (0);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (find_str(haystack, needle, len, i) == 1)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
