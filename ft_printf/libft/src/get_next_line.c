/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperra-f <yperra-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:59:16 by idunaver          #+#    #+#             */
/*   Updated: 2019/02/21 18:44:31 by yperra-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_get_result(char *konk, char *temp, char **line, char **ostatok)
{
	if (*konk)
	{
		if (temp != NULL && *temp != '\0')
		{
			if (!(*line = ft_strsub(konk, 0, ft_strlen(konk) - \
			ft_strlen(temp))) || !(*ostatok = \
			ft_strsub(temp, 1, ft_strlen(temp))))
			{
				ft_strdel(&konk);
				return (-1);
			}
			else
			{
				ft_strdel(&konk);
				return (1);
			}
		}
		else
		{
			*line = ft_strdup(*ostatok);
			ft_strdel(ostatok);
			return (1);
		}
	}
	return (0);
}

static int	ft_get(char *buff, char **ostatok, char **line, int fd)
{
	ssize_t	bytes;
	char	*konk;
	char	*temp;

	konk = *ostatok;
	if ((temp = ft_strchr(konk, '\n')) == NULL)
	{
		while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[bytes] = '\0';
			if (!(konk = ft_strjoin(*ostatok, buff)))
			{
				ft_strdel(&buff);
				return (-1);
			}
			ft_strdel(ostatok);
			if ((temp = ft_strchr(konk, '\n')) != NULL)
				break ;
			*ostatok = konk;
		}
	}
	ft_strdel(&buff);
	return (ft_get_result(konk, temp, line, ostatok));
}

int			get_next_line(const int fd, char **line)
{
	char		*buff;
	static char *ostatok[MAX_FD];
	int			result;

	if (fd >= MAX_FD)
		return (-1);
	if (!(buff = (char *)malloc(BUFF_SIZE + 1))\
	|| !line || read(fd, buff, 0) == -1)
	{
		ft_strdel(&buff);
		return (-1);
	}
	if (!ostatok[fd])
	{
		if (!(ostatok[fd] = ft_strnew(0)))
		{
			ft_strdel(&buff);
			return (-1);
		}
	}
	if ((result = ft_get(buff, &ostatok[fd], line, fd)) == 0)
		ft_strdel(&ostatok[fd]);
	return (result);
}
