/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:12:18 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/13 18:40:59 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*arr = NULL;
	char		*stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!arr)
	{
		arr = ft_getline(arr,fd);
		stash = ft_cleanline(arr);
		arr = ft_strchr(arr, '\n');
	}
	else {
		stash = ft_cleanline(arr);
		arr = ft_strchr(arr, '\n');
		if (!stash)
			return (NULL);
	}
	return (stash);
}
