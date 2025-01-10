/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:59:08 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/20 15:59:09 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_len(char const *s1, char const *s2)
{
	int	cnt;

	cnt = 0;
	while (*s1)
	{
		s1++;
		cnt++;
	}
	while (*s2)
	{
		s2++;
		cnt++;
	}
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*p;
	int		i;

	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	len = check_len(s1, s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == (void *)0)
		return (0);
	i = 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}
