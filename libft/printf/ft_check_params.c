/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:18:16 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:18:19 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_check_flags(char **str, t_arg *param)
{
	param->param_good = FALSE;
	while (**str == '#' || **str == '0' || **str == '-' || **str == '+' ||
			**str == ' ')
	{
		if (**str == '#')
			param->sharp = TRUE;
		else if (**str == '0')
			param->null = TRUE;
		else if (**str == '-')
			param->minus = TRUE;
		else if (**str == '+')
			param->plus = TRUE;
		else if (**str == ' ')
			param->space = TRUE;
		++(*str);
		param->param_good = TRUE;
	}
	return (param->param_good);
}

int	ft_check_width(char **str, t_arg *param)
{
	char	ok;

	ok = 0;
	if (ft_isdigit(**str) == GOOD)
	{
		param->is_width = TRUE;
		param->width = ft_atoi(*str);
		while (ft_isdigit(**str) == GOOD)
			++(*str);
		ok = 1;
	}
	else if (param->is_width != TRUE)
		param->is_width = FALSE;
	return (ok);
}

int	ft_check_precision(char **str, t_arg *param)
{
	char	ok;

	ok = 0;
	if (**str == '.')
	{
		++(*str);
		param->precision = ft_atoi(*str);
		while (ft_isdigit(**str) == 1)
			++(*str);
		param->is_pre = TRUE;
		ok = 1;
	}
	else if (param->is_pre != TRUE)
		param->is_pre = FALSE;
	return (ok);
}

int	ft_check_length(char **str, t_arg *param)
{
	t_length	len_tmp;

	len_tmp = 0;
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
		{
			len_tmp = *(*str + 1) == 'h' ? hh : h;
			(*str) += len_tmp == hh ? 1 : 0;
		}
		else if (**str == 'l')
		{
			len_tmp = *(*str + 1) == 'l' ? ll : l;
			(*str) += len_tmp == ll ? 1 : 0;
		}
		else if (**str == 'j')
			len_tmp = j;
		else if (**str == 'z')
			len_tmp = z;
		++(*str);
		param->len = param->len < len_tmp ? len_tmp : param->len;
	}
	else if (param->len != none)
		return (0);
	return (param->len);
}
