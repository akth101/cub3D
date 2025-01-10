/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:50:08 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 13:50:09 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*temp1 == '\0' && *temp2 == '\0')
			return (0);
		if (*temp1 != *temp2)
			return (*temp1 - *temp2);
		temp1++;
		temp2++;
		i++;
	}
	return (0);
}
