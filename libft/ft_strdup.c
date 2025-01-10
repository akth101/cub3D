/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:32:50 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 18:32:51 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		i;
	char		*temp;
	char		*p;

	i = 0;
	temp = (char *)s1;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == (void *)0)
		return (0);
	while (*temp)
		p[i++] = *temp++;
	p[i] = '\0';
	return (p);
}
