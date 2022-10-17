/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:54:08 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/08 18:21:31 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*target;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	if (!(target = malloc((j + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		target[i] = s[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != '\0')
		return (1);
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
