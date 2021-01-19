/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 11:40:07 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/12/23 13:39:36 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_pow(long long n, int power)
{
	long long ret;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	ret = 1;
	while (power--)
		ret *= n;
	return (ret);
}

int			min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int			max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
