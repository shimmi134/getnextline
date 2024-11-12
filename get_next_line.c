/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:12:18 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/12 19:19:20 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*arr = NULL;
	char		*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!arr)
	{
		temp = ft_getline(fd);
		if (!temp)
			return (free(temp),NULL);
		arr = ft_strchr(temp,'\n');
		stash = ft_cleanline(temp);
		if (!stash)
			return (NULL);
	}
	else {
		stash = ft_cleanline(arr);
		arr = ft_strchr(arr, '\n');
		if (!stash || arr == "\n")
		{
			return (free(arr),NULL);
		}
	}
	return (stash);
}
