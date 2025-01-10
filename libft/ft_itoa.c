/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:43:22 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/21 11:43:23 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	calib_sign_(int num, int *sign)
{
	long	res;

	res = 1;
	if (num < 0)
	{
		res = num;
		res *= -1;
		*sign = -1;
	}
	if (num > 0)
		res = num;
	if (num == 0)
		res = 0;
	return (res);
}

static char	*secure_space(long num, int *sign)
{
	char	*p;
	int		cnt;

	cnt = 0;
	while (num != 0)
	{
		num /= 10;
		cnt++;
	}
	if (*sign == -1)
	{
		p = (char *)malloc(sizeof(char) * (cnt + 1 + 1));
		if (p == (void *)0)
			return (0);
	}
	if (*sign == 1)
	{
		p = (char *)malloc(sizeof(char) * (cnt + 1));
		if (p == (void *)0)
			return (0);
	}
	return (p);
}

static int	cntnbr(long nb)
{
	int	cnt;

	cnt = 0;
	while (nb != 0)
	{
		nb /= 10;
		cnt++;
	}
	return (cnt - 1);
}

static char	*letsgo_input(long num, char *p, int *sign)
{
	long	result;
	long	remain;
	int		order;

	order = cntnbr(num);
	if (*sign == -1)
	{
		p[0] = '-';
		order++;
	}
	p[order + 1] = '\0';
	while (num != 0)
	{
		result = num / 10;
		remain = num % 10;
		p[order] = (char)(remain + '0');
		num = result;
		order--;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long	num;
	int		sign;
	char	*p;

	sign = 1;
	num = calib_sign_(n, &sign);
	if (num == 0)
	{
		p = (char *)malloc(sizeof(char) * 2);
		if (p == (void *)0)
			return (0);
		p[0] = '0';
		p[1] = '\0';
		return (p);
	}
	p = secure_space(num, &sign);
	if (p == (void *)0)
		return (0);
	p = letsgo_input(num, p, &sign);
	return (p);
}
