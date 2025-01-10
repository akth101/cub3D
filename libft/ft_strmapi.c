/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:14:02 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/21 16:14:03 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		i;
	int		strcnt;

	i = 0;
	strcnt = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * (strcnt + 1));
	if (ans == (void *)0)
		return (0);
	while (*s)
	{
		ans[i] = f(i, *s);
		i++;
		s++;
	}
	ans[i] = '\0';
	return (ans);
}
