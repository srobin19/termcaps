/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:23:59 by srobin            #+#    #+#             */
/*   Updated: 2020/03/04 11:23:59 by srobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	return (count);
}
