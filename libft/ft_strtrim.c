/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:11:29 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/20 16:11:32 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const *s1, char const *set)
{
	while (*set)
	{
		if (*s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*letsgo_malloc(int flag, int i, int j, char const *s1)
{
	char	*p;
	int		k;

	if (flag == 0)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (j - i + 2));
	if (p == (void *)0)
		return (0);
	k = 0;
	while (i <= j)
		p[k++] = s1[i++];
	p[k] = '\0';
	return (p);
}

static size_t	from_front(char const *s1, char const *set)
{
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(s1))
	{
		if (check_set(&s1[i], set) == 0)
			break ;
	}
	return (i);
}

static size_t	from_back(char const *s1, char const *set)
{
	size_t	j;

	j = ft_strlen(s1);
	while (--j >= 0)
	{
		if (check_set(&s1[j], set) == 0)
			break ;
	}
	return (j);
}	

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*p;

	if (*s1 == '\0')
		return (ft_strdup(""));
	i = from_front(s1, set);
	j = from_back(s1, set);
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	p = letsgo_malloc(1, i, j, s1);
	return (p);
}
