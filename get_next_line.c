/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiorgi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:18:31 by pgiorgi           #+#    #+#             */
/*   Updated: 2023/12/05 10:18:39 by pgiorgi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
		return (0);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char **buff)
{
	int		n_pos;
	char	*line;
	char	*str;

	if (!*buff)
		return (NULL);
	str = *buff;
	n_pos = 0;
	while (str[n_pos] && str[n_pos] != '\n')
		n_pos++;
	if (str[n_pos] == '\n')
		n_pos++;
	line = ft_strdup(str, n_pos);
	if (!line)
		return (NULL);
	*buff = ft_strdup(str + n_pos, ft_strlen(str + n_pos));
	if (str)
		free(str);
	str = (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*result;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buff), buff = NULL, NULL);
	if (ft_strchr(buff))
		return (extract_line(&buff));
	result = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!result)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, result, BUFFER_SIZE);
		result[bytes] = '\0';
		buff = ft_strjoin(buff, result);
		if (ft_strchr(buff))
			break ;
	}
	if (result)
		free(result);
	result = (NULL);
	return (extract_line(&buff));
}
// int main()
// {
//  int fd; 
//  fd = open("testo.txt", O_RDONLY);
//  char    *line;
//  //printf("%i", fd);
//  int i = 1;
//  while (i <= 2)
//  {
//      line = get_next_line(fd);
//      printf("LINE [%i] :\n%s\n", i, line);
//      i++;
//  }
// }
