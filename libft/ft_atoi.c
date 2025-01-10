/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:17:44 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/19 16:17:45 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	letsgo_atoi(const char *str)
{
	long long	num;

	num = 0;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9') && *str != '\n')
			return (-2147483649);
		if (*str == '\n')
			break ;
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num);
}

long long	ft_atoi(const char *str)
{
	int				sign;
	long long		ans;
	unsigned char	*temp;

	sign = 1;
	temp = (unsigned char *)str;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	if (*str == '\n')
		return (-2147483649);
	ans = letsgo_atoi(str);
	return (ans * sign);
}
