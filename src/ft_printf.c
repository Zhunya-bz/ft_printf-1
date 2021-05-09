/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvallie <lvallie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:18:59 by lvallie           #+#    #+#             */
/*   Updated: 2021/05/09 01:10:24 by lvallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_printf(char *string, ...)
{
	va_list	ap;
	int		printed_chars;

	printed_chars = 0;
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			if (!ft_converter(&string, ap, &printed_chars))
				return (-1);
		}
		else if (*string != '%')
		{
			write(1, string, 1);
			printed_chars++;
			string++;
		}
	}
	va_end(ap);
	return (printed_chars);
}
