/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:18:52 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/12/05 10:18:57 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(s2);
	if (!s1)
		return (ft_strdup(s2, len));
	if (!s2)
		return (NULL);
	len = len + ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	len = 0;
	while (s1[i])
		s3[len++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[len++] = s2[i++];
	s3[len] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(char *str, int len)
{
	char	*array;
	int		count;

	if (!str || !len)
		return (NULL);
	count = 0;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	while (count < len)
	{
		array[count] = str[count];
		count++;
	}
	array[count] = '\0';
	return (array);
}
