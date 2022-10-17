/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:08:37 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/04 16:52:47 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_post_stored(char *read_line)
{
	int		i;
	int		j;
	char	*post_stored;

	i = 0;
	j = 0;
	if (!read_line)
		return (0);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!read_line[i])
	{
		free(read_line);
		return (0);
	}
	if (!(post_stored = malloc(sizeof(char) * ((ft_strlen(read_line) - i) + 1))
))
		return (0);
	i++;
	while (read_line[i])
		post_stored[j++] = read_line[i++];
	post_stored[j] = '\0';
	free(read_line);
	return (post_stored);
}

char	*stored_line(char *read_line)
{
	int		i;
	char	*stored_line;

	i = 0;
	if (!read_line)
		return (0);
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (!(stored_line = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (read_line[i] && read_line[i] != '\n')
	{
		stored_line[i] = read_line[i];
		i++;
	}
	stored_line[i] = '\0';
	return (stored_line);
}

int		get_next_line(int fd, char **line)
{
	int				status;
	char			*buf;
	static char		*read_line;

	status = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (eotl(read_line) != 1 && status != 0)
	{
		if ((status = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[status] = '\0';
		read_line = tw_strjoin(read_line, buf);
	}
	free(buf);
	*line = stored_line(read_line);
	read_line = get_post_stored(read_line);
	if (status == 0)
		return (0);
	return (1);
}
