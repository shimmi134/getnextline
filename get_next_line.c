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
/*
 * 1. First check if my static array is empty or not
 * 1.1 If its empty, read n bytes and to the static array
 * 2. Then use strchr to find the first occurrance of a \n.
 * 2.1 If there's no \n, just return the array, and free the contents of it.
 * 2.2If there's a \n, find where it is, 
 * allocate memory for the length of it + 1 (\n) and null terminate it (+2 total)
 * 2.2 Then return up to the \n and end.
 * 1.2 If the array is not empty,, go to 2. 
 */
char	*get_next_line(int fd)
{
	static char	*arr = NULL;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		return (0);
	}
	temp = ft_splitline(arr, fd);
	//SPlit every function on a separate function
	return (temp);
}
