/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknsteja <mknsteja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:26:19 by mknsteja          #+#    #+#             */
/*   Updated: 2024/10/18 08:01:31 by mknsteja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char*	free_normal(char **str);
char *result(char *buffer_str, char *rem, char *finder);

char	*get_next_line(int fd)
{
    static char	*rem = NULL;
    char		*buffer_str;
    char		*finder;
	char		*temp;
    int			bytes_read;

    buffer_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer_str)
        return (free_normal(&buffer_str));
    while ((bytes_read = read(fd, buffer_str, BUFFER_SIZE)) > 0)
    {
        buffer_str[bytes_read] = '\0';
		temp = rem;
        rem = ft_strjoin(rem, buffer_str);
		if(temp)
			free(temp);
        if (!rem)
            return (free_normal(&buffer_str));
        finder = ft_strchr(rem, '\n');
        if (finder)
			return (result(buffer_str, rem, finder));
    }
    free_normal(&buffer_str);
    if (rem && *rem)
		result(buffer_str, rem, finder);
}

char *result(char *buffer_str, char *rem, char *finder)
{
	char *temp_rem;
	char *result;

	result = ft_substr(rem, 0, finder - rem + 1);
	temp_rem = rem;
	rem = ft_strdup(finder + 1);
	free(temp_rem);
	free_normal(&buffer_str);
	return (result);
}

char*	free_normal(char **str)
{
    if (str && *str)
    {
        free(*str);
        *str = NULL;
    }
	return(NULL);
}
