/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:26:19 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/18 09:10:26 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_normal(char **str);
char	*result(char *buffer_str, char **rem, char *finder);
char	*free_all(char **buffer_str, char **rem);
char	*free_final(char **rem, char *buffer_str);

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*buffer_str;
	char		*finder;
	char		*temp;
	int			bytes_read;

	buffer_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_str)
		return (free_all(&buffer_str, &rem));
	while ((bytes_read = read(fd, buffer_str, BUFFER_SIZE)) > 0)
	{
		buffer_str[bytes_read] = '\0';
		temp = rem;
		rem = ft_strjoin(rem, buffer_str);
		if (temp)
			free(temp);
		if (!rem)
			return (free_all(&buffer_str, &rem));
		finder = ft_strchr(rem, '\n');
		if (finder)
			return (result(buffer_str, &rem, finder));
	}
	return (free_final(&rem, buffer_str));
}

char	*free_final(char **rem, char *buffer_str)
{
	char	*result;

	result = NULL;
	free_normal(&buffer_str);
	if (rem && *rem)
	{
		result = ft_strdup(*rem);
		free_normal(rem);
		return (result);
	}
	return (NULL);
}

char	*free_all(char **buffer_str, char **rem)
{
	(void)free_normal(buffer_str);
	(void)free_normal(rem);
	return (NULL);
}

char	*result(char *buffer_str, char **rem, char *finder)
{
	char	*temp_rem;
	char	*result;

	result = ft_substr(*rem, 0, finder - *rem + 1);
	temp_rem = *rem;
	*rem = ft_strdup(finder + 1);
	free(temp_rem);
	free_normal(&buffer_str);
	return (result);
}

char	*free_normal(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
