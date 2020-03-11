/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobin   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:06 by srobin           #+#    #+#              */
/*   Updated: 2020/03/04 11:54:07 by srobin          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*copy;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(src);
	if (n > size)
		n = size;
	copy = ft_strnew(n);
	if (copy == NULL)
		return (NULL);
	while (src[i] && i < n)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
