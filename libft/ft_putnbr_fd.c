/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:06:18 by seongjko          #+#    #+#             */
/*   Updated: 2023/03/21 18:06:19 by seongjko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	calib_sign(long num, int fd)
{
	long	res;

	res = -1;
	if (num < 0)
	{
		write(fd, "-", 1);
		res = num * (-1);
		return (res);
	}
	if (num > 0)
	{
		res = num;
		return (res);
	}
	return (0);
}

static void	run(long num, int fd)
{
	char	temp;

	if (num == 0)
		return ;
	run(num / 10, fd);
	temp = (char)(num % 10 + '0');
	write(fd, &temp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
		num = calib_sign(n, fd);
	run(num, fd);
}
