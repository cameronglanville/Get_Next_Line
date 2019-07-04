/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglanvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:18:08 by cglanvil          #+#    #+#             */
/*   Updated: 2019/07/04 16:22:53 by cglanvil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char		*buff[BUFF_SIZE + 1];
	char			*temp;
	int				ret;
	int				i;
	int				j;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	i = 0;
	j = 0;
	*line = strdup("");
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = "\0";
		temp = *line;
		ft_strjoin(*line, (char const*)buff);
		free(temp);
		if (ft_strchr((char const*)buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0)
	{
		free(buff);
		return (0);
	}
	return (1);
}
