/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 10:02:34 by hmeys             #+#    #+#             */
/*   Updated: 2018/10/27 11:46:30 by hmeys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[y] != '\0')
	{
		s1[i] = s2[y];
		i++;
		y++;
	}
	s1[i] = '\0';
	return (s1);
}
