/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losuna-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:14:42 by losuna-b          #+#    #+#             */
/*   Updated: 2019/01/22 12:46:21 by losuna-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_line(const int fd, char **array)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	ret = 0;
	while (ft_strchr(array[fd], '\n') == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (ret < 0)
			return (-1);
		if (ret == 0)
			return (0);
		temp = array[fd];
		if ((array[fd] = ft_strjoin(temp, buff)) == NULL)
			return (-1);
		ft_strdel(&temp);
	}
	return (1);
}

int		write_line(const int fd, char **array, char **line)
{
	char *temp;
	char *new_addr;

	if (array[fd][0] == '\0')
	{
		ft_strdel(&array[fd]);
		return (0);
	}
	if ((*line = ft_strndup(array[fd], ft_strclen(array[fd], '\n'))) == NULL)
	{
		if (array[fd] != NULL)
			ft_strdel(&array[fd]);
		return (-1);
	}
	temp = array[fd];
	if ((new_addr = ft_strchr(temp, '\n')) == NULL)
	{
		if (array[fd] != NULL)
			ft_strdel(&array[fd]);
		return (1);
	}
	if ((array[fd] = ft_strdup(new_addr + 1)) == NULL)
		return (-1);
	ft_strdel(&temp);
	return (1);
}

int		reset_array(char **array, int reset, int fd)
{
	if (reset > 0)
	{
		ft_strdel(&array[fd]);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line, int reset)
{
	static char *array[OPEN_MAX];
	int			read;

	if (reset_array(array, reset, fd))
		return (0);
	if (fd < 0 || fd > OPEN_MAX || line == NULL)
		return (-1);
	if (array[fd] != NULL && ft_strchr(array[fd], '\n') != NULL)
	{
		write_line(fd, array, line);
		return (1);
	}
	array[fd] = ((array[fd] == NULL) ? ft_strdup("") : array[fd]);
	if (array[fd] == NULL)
		return (-1);
	read = read_line(fd, array);
	if (read == -1)
	{
		if (array[fd] != NULL)
			ft_strdel(&array[fd]);
		return (-1);
	}
	return (write_line(fd, array, line));
}
