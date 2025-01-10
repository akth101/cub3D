/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:57:34 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/17 15:57:36 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len >= dstsize)
		return (src_len + dstsize);
	while (*dst)
	{
		dst++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (dest_len + src_len);
}
