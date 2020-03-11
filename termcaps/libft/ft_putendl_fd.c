/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 10:31:14 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/20 09:51:29 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != 0)
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}