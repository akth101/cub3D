/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:21:06 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/15 18:21:08 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	i = -1;
	while (++i < n)
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
	return (dst);
}
