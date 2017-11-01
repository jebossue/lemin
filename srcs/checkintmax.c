/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:32:02 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 13:53:11 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		checkintmax(char *str)
{
	int		i;
	int		sign;
	int		length;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	length = ft_strlen(str + i);
	if (length < 10 || (length == 10 && str[i] < '2'))
		return (1);
	if (length > 10 || (length == 10 && str[i] > '2'))
		return (0);
	if (length == 10 && str[i] == '2')
	{
		if (sign > 0 && ft_atoi(str + i + 1) > 147483647)
			return (0);
		if (sign < 0 && ft_atoi(str + i + 1) > 147483648)
			return (0);
	}
	return (1);
}
