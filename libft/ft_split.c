/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:16:38 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/20 17:16:39 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lets_cnt_str(char const *s, int c)
{
	int		cnt;
	int		flag;
	char	*p;

	cnt = 0;
	flag = 0;
	p = (char *)s;
	while (*s)
	{
		if (flag == 0 && *s != c)
		{
			cnt++;
			flag = 1;
		}
		if (flag == 1 && *s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

static char	*letsgo_malloc2(char const *stt, char *c)
{
	int		size;
	char	*temp;
	char	*p;
	int		i;

	size = 0;
	temp = (char *)stt;
	i = 0;
	while (*stt != *c && *stt)
	{
		stt++;
		size++;
	}
	p = (char *)malloc((sizeof(char) * (size + 1)));
	if (p == (void *)0)
		return (0);
	while (*temp != *c && *temp)
	{
		p[i++] = *temp;
		temp++;
	}
	p[i] = '\0';
	return (p);
}

static void	doomsday_malloc(char **ans, int i)
{
	--i;
	while (i >= 0)
	{
		free(*(ans + i));
		i--;
	}
	free(ans);
}

static int	letsgo_malloc1(char const *s, char **ans, int str_cnt, char c)
{
	int		i;
	char	*p;

	i = 0;
	while (*s && i < str_cnt)
	{
		if (*s != c)
		{
			p = letsgo_malloc2(s, &c);
			if (p == (void *)0)
			{
				doomsday_malloc(ans, i);
				return (0);
			}
			*(ans + i) = p;
			i++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	*(ans + i) = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		str_cnt;

	ans = (void *)0;
	str_cnt = lets_cnt_str(s, c);
	if (str_cnt == 0)
	{
		ans = (char **)malloc(sizeof(char *) * 1);
		if (ans == (void *)0)
			return (0);
		*ans = (void *)0;
		return (ans);
	}
	ans = (char **)malloc(sizeof(char *) * (str_cnt + 1));
	if (ans == (void *)0)
		return (0);
	if (letsgo_malloc1(s, ans, str_cnt, c) == 0)
		return (0);
	return (ans);
}
